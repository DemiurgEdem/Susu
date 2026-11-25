# Лабораторная работа 5: предобработка данных для ML и основы аналитики

**Дисциплина:** Аналитика данных / Введение в машинное обучение
**Тема:** масштабирование, кодирование категорий, ColumnTransformer, декомпозиция задач и выборки
**Среда:** Jupyter Notebook, Python 3.x, pandas, scikit-learn, matplotlib
**Отчётность:** ноутбук с выполненными ячейками и письменными ответами

---

## Цель работы

Научиться осознанно выбирать методы предобработки данных под конкретную задачу и не допускать типичных ошибок: утечки данных, неверного кодирования категорий, нерепрезентативных выборок.

После выполнения работы студент должен уметь:

1. Обосновывать выбор скейлера под распределение и наличие выбросов.
2. Кодировать категориальные признаки с учётом их типа.
3. Собирать препроцессинг в `ColumnTransformer` без утечки.
4. Формулировать SMART-цель и строить MECE-декомпозицию.
5. Строить репрезентативные выборки и распознавать систематические смещения.

---

## Подготовка

В работе используется синтетический датасет клиентов банка. Он создаётся ячейкой ниже и сохраняется в `bank_customers.csv`.

Целевая переменная `Churn` зависит от нескольких признаков — это нужно, чтобы модель в конце работы могла выучить реальный сигнал, а не шум.

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import (
    MinMaxScaler, StandardScaler, RobustScaler,
    LabelEncoder, OrdinalEncoder, OneHotEncoder
)
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split

plt.rcParams['figure.figsize'] = (10, 5)
plt.rcParams['font.size'] = 11
plt.rcParams['axes.grid'] = True

np.random.seed(42)
n = 800

df = pd.DataFrame({
    'Age':         np.random.randint(18, 76, n),
    'Income':      np.random.lognormal(mean=10.5, sigma=0.9, size=n).round(0),
    'Tenure':      np.random.randint(1, 61, n),
    'CreditScore': np.random.randint(300, 851, n),
    'Gender':      np.random.choice(['M', 'F'], n, p=[0.55, 0.45]),
    'Education':   np.random.choice(
                       ['High School', 'Bachelor', 'Master', 'PhD'],
                       n, p=[0.30, 0.45, 0.20, 0.05]),
    'City':        np.random.choice(
                       ['Moscow', 'SPb', 'Kazan', 'Ufa',
                        'Novosibirsk', 'Ekaterinburg'], n),
})

# Один выброс в доходе для демонстрации
df.loc[0, 'Income'] = 5_000_000

# Целевая переменная зависит от признаков
churn_logit = (
    -0.8
    + 0.04 * (df['Age'] - 45)
    + 1.2 * (df['Tenure'] < 12).astype(int)
)
p_churn = 1 / (1 + np.exp(-churn_logit))
df['Churn'] = np.random.binomial(1, p_churn)

df.to_csv('bank_customers.csv', index=False)

print(df.head())
print(f"Размер: {df.shape}")
print(f"Средний Churn: {df['Churn'].mean():.3f}")
print(df.dtypes)
```

После запуска убедитесь, что:

- датасет содержит 800 строк и 8 столбцов;
- в столбце `Income` первой строки стоит значение 5 000 000 (выброс);
- средний `Churn` около 0,3.

---

## Часть 1. Аналитика: постановка задачи

### Задание 1.1. SMART-формулировка

Бизнес ставит задачу так: «хотим снизить отток клиентов». Это не является постановкой задачи — в ней нет метрики, сегмента, срока и способа проверки.

Переформулируйте задачу в SMART-формате по шаблону:

> Снизить \<метрика> на \<X %> в сегменте \<сегмент> за \<срок> за счёт \<действие>.

Запишите формулировку в ячейку и распишите каждый элемент SMART.

```python
smart_goal = "..."
# Распишите каждый элемент
```

**Требования:** в формулировке присутствуют метрика с числом, сегмент, срок и действие. Все пять элементов SMART раскрыты.

---

### Задание 1.2. Декомпозиция «Почему клиенты уходят»

Постройте MECE-дерево глубины 2–3 уровня. Каждый лист дерева должен соответствовать метрике, которую можно посчитать на текущем датасете. Дерево оформите в виде вложенного словаря Python и напишите функцию обхода.

Минимальный набор веток верхнего уровня:

- число активных клиентов (новые и уходящие существующие);
- доход, приносимый клиентом (на клиента, частота операций);
- качество обслуживания (обращения в поддержку, скорость ответа).

Листья заполните сами — например, `churn_rate`, `avg_income_per_client`, `avg_tenure_of_churned`.

```python
decomposition_tree = { ... }

def print_tree(tree, level=0):
    ...

print_tree(decomposition_tree)
```

**Дополнительно письменно ответьте:**

- Дерево взаимоисключающее? Если нет — какие ветки пересекаются?
- Дерево полное? Если нет — что упущено?
- Все листья измеримы на текущем датасете? Если нет — какие данные нужно запросить.

---

### Задание 1.3. Типы смещений выборки

Для каждого сценария укажите тип систематического смещения: `selection`, `survivorship`, `response`, `recall`.

1. Аналитик изучает успешные стартапы, чтобы вывести формулу успеха.
2. Опрос «довольны ли вы сервисом?» проводится на сайте банка.
3. Модель обучали на клиентах, пришедших через рекламу Google.
4. Пользователей спрашивают «сколько раз вы были в банке в прошлом году».

Ответ запишите в словарь и выведите на экран с коротким (1–2 предложения) обоснованием.

---

## Часть 2. Первичный анализ данных

### Задание 2.1. Классификация признаков

Разделите исходные признаки (все столбцы, кроме `Churn`) на три группы:

- числовые;
- номинальные (нет порядка);
- порядковые (порядок есть).

```python
numeric_cols = ['Age', 'Income', 'Tenure', 'CreditScore']
nominal_cols = ['Gender', 'City']
ordinal_cols = ['Education']

original_cols = {'Age', 'Income', 'Tenure', 'CreditScore',
                 'Gender', 'Education', 'City'}
covered = set(numeric_cols) | set(nominal_cols) | set(ordinal_cols)
assert original_cols == covered, f"Пропущены: {original_cols - covered}"
print("Все признаки распределены по типам")
```

Письменно обоснуйте, почему `Education` относится к порядковым, а `City` — к номинальным.

---

### Задание 2.2. Анализ выбросов

Выведите `describe()` для числовых столбцов. Посчитайте количество выбросов по правилу трёх сигм (`|z| > 3`) для каждого столбца.

```python
print(df[numeric_cols].describe().round(1))

z_scores = (df[numeric_cols] - df[numeric_cols].mean()) / df[numeric_cols].std()
print((z_scores.abs() > 3).sum())
```

**Ответьте письменно:** в каком столбце есть выброс, какой скейлер вы выберете для этого столбца и почему.

---

## Часть 3. Масштабирование

### Задание 3.1. Сравнение скейлеров

Примените `MinMaxScaler`, `StandardScaler` и `RobustScaler` к столбцу `Income`. Постройте четыре гистограммы в одном ряду: исходный доход, после Min-Max, после Standard, после Robust.

```python
fig, axes = plt.subplots(1, 4, figsize=(18, 4))
# постройте четыре гистограммы с заголовками и подписями осей
plt.tight_layout()
plt.show()
```

**Ответьте письменно:**

1. После какого скейлера форма распределения сохранилась лучше всего?
2. Какой скейлер сильнее всего пострадал от единственного выброса?
3. Какой скейлер вы выберете для `Income` в продакшене и почему?

---

### Задание 3.2. Выбор скейлера по признаку

Заполните таблицу для четырёх числовых признаков: скейлер и краткое (1–2 предложения) обоснование.

| Признак | Скейлер | Обоснование |
|---------|---------|-------------|
| Age | | |
| Income | | |
| Tenure | | |
| CreditScore | | |

Оформите как словари `scaler_choice` и `justification`, выведите в цикле.

---

## Часть 4. Кодирование категорий

### Задание 4.1. Label и One-Hot для `Gender`

Закодируйте `Gender` через `LabelEncoder` и через `pd.get_dummies`. Выведите результат.

```python
df['Gender_Label'] = LabelEncoder().fit_transform(df['Gender'])
df_ohe = pd.get_dummies(df['Gender'], prefix='Gender', dtype=int)
print(df_ohe.head())
```

**Ответьте письменно:** для каких моделей Label-кодирование допустимо, а для каких — нет? Обоснуйте.

---

### Задание 4.2. Ordinal-кодирование `Education`

`Education` — порядковый признак. Закодируйте его через `OrdinalEncoder` с **явно заданным** порядком: `High School < Bachelor < Master < PhD`.

```python
edu_order = [...]  # заполните сами
oe = OrdinalEncoder(categories=[edu_order])
df['Education_Ord'] = oe.fit_transform(df[['Education']])
print(df[['Education', 'Education_Ord']].drop_duplicates().sort_values('Education_Ord'))
```

**Ответьте письменно:** что было бы, если не задать `categories` явно? Какие значения получили бы категории и насколько это соответствует реальному порядку?

---

### Задание 4.3. Frequency-кодирование `City`

Закодируйте `City` через частоту встречаемости.

```python
freq_map = df['City'].value_counts()
df['City_Freq'] = df['City'].map(freq_map)
print(df[['City', 'City_Freq']].drop_duplicates())
```

**Ответьте письменно:** в чём главный недостаток Frequency-кодирования? В каком сценарии этот недостаток критичен?

---

## Часть 5. ColumnTransformer

### Задание 5.1. Полный препроцессинг

Соберите единый `ColumnTransformer`, который:

- к `Age`, `CreditScore` применяет `StandardScaler`;
- к `Income` — `RobustScaler`;
- к `Tenure` — `MinMaxScaler`;
- к `Gender`, `City` — `OneHotEncoder(drop='first')`;
- к `Education` — `OrdinalEncoder` с тем же порядком, что в задании 4.2.

Данные на train/test разделите **до** `fit`.

```python
X = df.drop(columns=['Churn', 'Gender_Label', 'Education_Ord', 'City_Freq'],
            errors='ignore')
y = df['Churn']

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=42, stratify=y
)

preprocessor = ColumnTransformer(transformers=[ ... ])
X_train_prepared = preprocessor.fit_transform(X_train)
X_test_prepared = preprocessor.transform(X_test)

print(X_train.shape, '->', X_train_prepared.shape)
print(X_test.shape, '->', X_test_prepared.shape)
```

**Ожидаемая форма:** `(600, 7) → (600, 11)` и `(200, 7) → (200, 11)`.

Проверка по столбцам: Age и CreditScore дают 2, Income — 1, Tenure — 1, Gender — 1 (drop='first'), City — 5 (drop='first'), Education — 1. Итого 11.

**Ответьте письменно на три вопроса:**

1. Почему `fit_transform` применяется только к train, а к test — только `transform`?
2. Сколько столбцов даст `OneHotEncoder(drop='first')` на `Gender`? На `City`?
3. Что произойдёт, если в test встретится город, которого не было в train? Как это обрабатывается в sklearn по умолчанию и как можно изменить поведение?

---

## Часть 6. Выборки

### Задание 6.1. Простая случайная и стратифицированная выборки

Сделайте две выборки по 100 строк:

- простую случайную (`df.sample`);
- стратифицированную по `Churn` — реализуйте функцию `stratified_sample` самостоятельно.

Подсказка: `df[strat_col].value_counts(normalize=True)` даёт доли групп, а `.sample(n=..., random_state=...)` — случайную выборку внутри группы.

```python
def stratified_sample(df, strat_col, n_total, random_state=42):
    # ваш код здесь
    ...

s_rand = df.sample(n=100, random_state=42)
s_strat = stratified_sample(df, 'Churn', n_total=100)

print(f"Популяция:            {df['Churn'].mean():.3f}")
print(f"Случайная:            {s_rand['Churn'].mean():.3f}")
print(f"Стратифицированная:   {s_strat['Churn'].mean():.3f}")
```

**Ответьте письменно:**

1. Какая выборка ближе к популяции по доле `Churn`?
2. Почему при стратификации по `Churn` столбец `Churn` нельзя оставлять среди признаков `X` при обучении модели?

---

### Задание 6.2. Влияние размера выборки на оценку

Сгенерируйте по 100 выборок каждого размера: `n ∈ {20, 100, 500}`. Для каждой посчитайте **медиану** `Income` (медиана устойчива к единственному выбросу в 5 000 000, поэтому именно она покажет масштаб эффекта). Постройте `boxplot` для трёх серий и горизонтальную линию на уровне медианы по всей популяции.

```python
sizes = [20, 100, 500]
results = {n: [] for n in sizes}
for n in sizes:
    for seed in range(100):
        results[n].append(df.sample(n=n, random_state=seed)['Income'].median())

fig, ax = plt.subplots()
ax.boxplot([results[n] for n in sizes], labels=[f'n={n}' for n in sizes])
ax.axhline(df['Income'].median(), color='red', linestyle='--',
           label=f"Медиана в популяции = {df['Income'].median():,.0f}")
ax.set_ylabel('Медиана Income')
ax.legend()
plt.show()

for n in sizes:
    print(f"n={n}: std = {np.std(results[n]):,.0f}")
```

**Ответьте письменно:** как меняется стандартное отклонение оценки медианы с ростом `n`? Согласуется ли это с формулой стандартной ошибки `σ / √n`? Что произошло бы, если бы вместо медианы вы считали среднее?


## Форма отчёта

В ноутбуке должны быть:

- все ячейки `TODO` заполнены и выполняются без ошибок;
- письменные ответы — в markdown-ячейках сразу после соответствующего задания;
- графики — с заголовками и подписями осей;
- ноутбук сохранён с выполненными ячейками (output виден).

---

