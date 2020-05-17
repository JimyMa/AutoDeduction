@echo off

cd ../openssl

echo Generate server privite key:
openssl genrsa -out privkey.pem 2048

echo Generate server  cacert:
openssl req -new -x509 -key privkey.pem -out cacert.pem -days 1095  -subj  "/C=CN/ST=CA/L=Cupertino/O=YourCompany/OU=AutoDeduction/CN=localhost"

echo Generate client privite key:
openssl genrsa -out privkey.pem 2048

echo Generate client cacert:
openssl req -new -x509 -key privkey.pem -out cacert.pem -days 1095  -subj  "/C=CN/ST=CA/L=Cupertino/O=YourCompany/OU=AutoDeduction/CN=localhost"

cd ..
