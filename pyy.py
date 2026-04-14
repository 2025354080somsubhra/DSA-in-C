# import numpy as np
# import matplotlib.pyplot as plt

# x = np.linspace(-10, 10, 100)

# y = x**2 + 2*x
# z = np.sin(y)

# plt.plot(x, y, label="y = x^2 + 2x")
# plt.plot(x, z, label="z = sin(y)")

# plt.legend()
# plt.title("Comparison Plot")
# plt.show()

# import numpy as np
# import matplotlib.pyplot as plt

# marks = np.random.randint(0, 21, 60)

# plt.hist(marks)
# plt.title("Histogram of Marks")
# plt.xlabel("Marks")
# plt.ylabel("Number of Students")
# plt.show()

import pandas as pd
import matplotlib.pyplot as plt

data = {
    'Month': ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun'],
    'Sales': [2000, 3000, 2500, 4000, 3500, 4500]
}

df = pd.DataFrame(data)

print("Total Sales:", df['Sales'].sum())

print(df[df['Sales'] == df['Sales'].max()])

plt.pie(df['Sales'], labels=df['Month'], autopct='%1.1f%%')
plt.title("Monthly Sales Distribution")
plt.show()

