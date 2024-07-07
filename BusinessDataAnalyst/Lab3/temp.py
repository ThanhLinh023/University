import pandas as pd
import numpy as np
data = pd.read_csv("historical_air_quality_2021_en.csv")
data = data[data['Dominent pollutant'].isin(['pm25', 'pm10'])]
df = data[['AQI index', 'Dominent pollutant', 'PM10', 'PM2.5']]
df.replace("-", np.nan, inplace=True)
df.replace(" ", np.nan, inplace=True)
df = df.dropna()
df.to_csv("two_attr.csv", index=False)