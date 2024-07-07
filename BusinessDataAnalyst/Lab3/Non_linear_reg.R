data<-read.csv(file.choose())
attach(data)
ln_reg = lm(formula = data$AQI.index~log10(1/data$PM10)+log10(1/data$PM2.5))
summary(ln_reg)
rel_pm10_aqi = lm(formula = data$AQI.index~log10(1/data$PM10))
summary(rel_pm10_aqi)

rel_pm25_aqi = lm(formula = data$AQI.index~log10(1/data$PM2.5))
summary(rel_pm25_aqi)