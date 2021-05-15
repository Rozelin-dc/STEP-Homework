data <- read.csv("./ex1-result.csv")
plot(data, type="p")
par(new="T", xaxt  = "n", yaxt = "n")
y <- function(x){x^3}
plot(y, 0, 1000, xlab="", ylab="", col="blue")
