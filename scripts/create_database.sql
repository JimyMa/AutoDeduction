# 新建数据库
CREATE DATABASE auto_deduction;
use auto_deduction;

# 创建用户数据表
CREATE TABLE user  (
  id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  name VARCHAR(255)
) character set= utf8;

# 创建付费服务数据表
CREATE TABLE service  (
  id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  name VARCHAR(255)
) character set= utf8;

# 创建用户订阅数据表
CREATE TABLE user_book_info  (
  id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  user_id INT,
  service_id INT
) character set= utf8;
