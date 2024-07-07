data_use<-read.csv(file.choose())
attach(data_use)
cov(mediansat, graduation)
cor(mediansat, graduation)