/*
SQLyog Ultimate v11.24 (32 bit)
MySQL - 8.0.24 : Database - myshop
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`myshop` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `myshop`;

/*Table structure for table `customers` */

DROP TABLE IF EXISTS `customers`;

CREATE TABLE `customers` (
  `cust_id` int NOT NULL AUTO_INCREMENT,
  `cust_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `cust_password` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `cust_status` bit(1) DEFAULT NULL,
  `cust_phone` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `cust_address` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`cust_id`) USING BTREE,
  KEY `cust_name` (`cust_name`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=988 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `customers` */

insert  into `customers`(`cust_id`,`cust_name`,`cust_password`,`cust_status`,`cust_phone`,`cust_address`) values (45,'张三','MTIz','',NULL,NULL);

/*Table structure for table `goods` */

DROP TABLE IF EXISTS `goods`;

CREATE TABLE `goods` (
  `good_id` int NOT NULL,
  `good_name` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `good_price` double(20,1) DEFAULT NULL,
  `type_id` int DEFAULT NULL,
  `good_detail` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `good_icon_url` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `good_image_detail_url` varchar(300) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `pic_url` varchar(300) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`good_id`) USING BTREE,
  KEY `fk_type_id` (`type_id`) USING BTREE,
  CONSTRAINT `fk_type_id` FOREIGN KEY (`type_id`) REFERENCES `types` (`type_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `goods` */

insert  into `goods`(`good_id`,`good_name`,`good_price`,`type_id`,`good_detail`,`good_icon_url`,`good_image_detail_url`,`pic_url`) values (101,'红富士   1公斤',19.9,1,'有货','apple1.jpg','apple1.jpg,apple2.jpg,apple3.jpg,apple4.jpg','http://localhost:8080/myshop/images/apple1.jpg'),(102,'黄元帅   1公斤',19.9,1,'有货','apple2.jpg','apple1.jpg,apple2.jpg,apple3.jpg,apple4.jpg','http://localhost:8080/myshop/images/apple2.jpg'),(103,'红星     1公斤',19.9,1,'有货','apple3.jpg','apple1.jpg,apple2.jpg,apple3.jpg,apple4.jpg','http://localhost:8080/myshop/images/apple3.jpg'),(104,'国光     1公斤',19.9,1,'有货','apple4.jpg','apple1.jpg,apple2.jpg,apple3.jpg,apple4.jpg','http://localhost:8080/myshop/images/apple4.jpg'),(105,'三月红   1公斤',18.9,2,'有货','litchi1.jpg','litchi1.jpg,litchi2.jpg,litchi3.jpg,litchi4.jpg','http://localhost:8080/myshop/images/litchi1.jpg'),(106,'妃子笑   1公斤',18.9,2,'有货','litchi2.jpg','litchi1.jpg,litchi2.jpg,litchi3.jpg,litchi4.jpg','http://localhost:8080/myshop/images/litchi2.jpg'),(107,'白糖罂   1公斤',18.9,2,'无货','litchi3.jpg','litchi1.jpg,litchi2.jpg,litchi3.jpg,litchi4.jpg','http://localhost:8080/myshop/images/litchi3.jpg'),(108,'糯米糍   1公斤',18.9,2,'无货','litchi4.jpg','litchi1.jpg,litchi2.jpg,litchi3.jpg,litchi4.jpg','http://localhost:8080/myshop/images/litchi4.jpg'),(109,'沙糖桔   1公斤',17.9,3,'有货','orange1.jpg','orange1.jpg,orange2.jpg,orange3.jpg,orange4.jpg','http://localhost:8080/myshop/images/orange1.jpg'),(201,'贡桔     1公斤',17.9,3,'有货','orange2.jpg','orange1.jpg,orange2.jpg,orange3.jpg,orange4.jpg','http://localhost:8080/myshop/images/orange2.jpg'),(202,'四季桔   1公斤',17.9,3,'有货','orange3.jpg','orange1.jpg,orange2.jpg,orange3.jpg,orange4.jpg','http://localhost:8080/myshop/images/orange3.jpg'),(203,'红桔     1公斤',17.9,3,'无货','orange4.jpg','orange1.jpg,orange2.jpg,orange3.jpg,orange4.jpg','http://localhost:8080/myshop/images/orange4.jpg'),(204,'水仙芒   1公斤',20.9,4,'有货','mango1.jpg','mango1.jpg,mango2.jpg,mango3.jpg,mango4.jpg','http://localhost:8080/myshop/images/mango1.jpg'),(205,'苹果芒   1公斤',20.9,4,'有货','mango2.jpg','mango1.jpg,mango2.jpg,mango3.jpg,mango4.jpg','http://localhost:8080/myshop/images/mango2.jpg'),(206,'苹果芒   1公斤',20.9,4,'有货','mango3.jpg','mango1.jpg,mango2.jpg,mango3.jpg,mango4.jpg','http://localhost:8080/myshop/images/mango3.jpg'),(207,'澳洲芒   1公斤',20.9,4,'有货','mango4.jpg','mango1.jpg,mango2.jpg,mango3.jpg,mango4.jpg','http://localhost:8080/myshop/images/mango4.jpg'),(208,'红心火龙果 1公斤',16.9,5,'无货','dragonfruit1.jpg','dragonfruit1.jpg,dragonfruit2.jpg,dragonfruit3.jpg,dragonfruit4.jpg','http://localhost:8080/myshop/images/dragonfruit1.jpg'),(209,'白心火龙果 1公斤',16.9,5,'有货','dragonfruit2.jpg','dragonfruit1.jpg,dragonfruit2.jpg,dragonfruit3.jpg,dragonfruit4.jpg','http://localhost:8080/myshop/images/dragonfruit2.jpg'),(210,'黄皮火龙果 1公斤',16.9,5,'有货','dragonfruit3.jpg','dragonfruit1.jpg,dragonfruit2.jpg,dragonfruit3.jpg,dragonfruit4.jpg','http://localhost:8080/myshop/images/dragonfruit3.jpg'),(301,'红灯     1公斤',23.9,6,'有货','cherry1.jpg','cherry1.jpg,cherry2.jpg,cherry3.jpg,cherry4.jpg','http://localhost:8080/myshop/images/cherry1.jpg'),(302,'早红宝石 1公斤',23.9,6,'有货','cherry2.jpg','cherry1.jpg,cherry2.jpg,cherry3.jpg,cherry4.jpg','http://localhost:8080/myshop/images/cherry2.jpg'),(303,'美早     1公斤',23.9,6,'有货','cherry3.jpg','cherry1.jpg,cherry2.jpg,cherry3.jpg,cherry4.jpg','http://localhost:8080/myshop/images/cherry3.jpg'),(304,'早大果   1公斤',23.9,6,'有货','cherry4.jpg','cherry1.jpg,cherry2.jpg,cherry3.jpg,cherry4.jpg','http://localhost:8080/myshop/images/cherry4.jpg');

/*Table structure for table `og` */

DROP TABLE IF EXISTS `og`;

CREATE TABLE `og` (
  `order_id` int NOT NULL,
  `good_id` int NOT NULL,
  `good_num` int DEFAULT NULL,
  PRIMARY KEY (`order_id`,`good_id`) USING BTREE,
  CONSTRAINT `fk_og_order` FOREIGN KEY (`order_id`) REFERENCES `orders` (`order_id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `og` */

/*Table structure for table `orders` */

DROP TABLE IF EXISTS `orders`;

CREATE TABLE `orders` (
  `order_id` int NOT NULL AUTO_INCREMENT,
  `cust_id` int DEFAULT NULL,
  `order_status` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `pay_mode` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `order_time` datetime DEFAULT CURRENT_TIMESTAMP,
  `order_remark` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `order_price` double DEFAULT NULL,
  `rec_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `rec_phone` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `rec_address` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `logistics_progress` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `logistics_status` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`order_id`) USING BTREE,
  KEY `cust_id` (`cust_id`) USING BTREE,
  KEY `rec_name` (`rec_name`) USING BTREE,
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`cust_id`) REFERENCES `customers` (`cust_id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=9399 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `orders` */

/*Table structure for table `sys_user` */

DROP TABLE IF EXISTS `sys_user`;

CREATE TABLE `sys_user` (
  `user_id` int NOT NULL,
  `user_name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `user_password` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`user_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `sys_user` */

insert  into `sys_user`(`user_id`,`user_name`,`user_password`) values (1,'abc','123'),(2,'def','123');

/*Table structure for table `types` */

DROP TABLE IF EXISTS `types`;

CREATE TABLE `types` (
  `type_id` int NOT NULL,
  `type_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `type_url` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`type_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;

/*Data for the table `types` */

insert  into `types`(`type_id`,`type_name`,`type_url`) values (1,'苹果','http://localhost:8090/myshop/images/apple1.jpg'),(2,'荔枝','http://localhost:8090/myshop/images/litchi1.jpg'),(3,'橘子','http://localhost:8090/myshop/images/orange1.jpg'),(4,'芒果','http://localhost:8090/myshop/images/mango1.jpg'),(5,'火龙果','http://localhost:8090/myshop/images/dragonfruit1.jpg'),(6,'樱桃','http://localhost:8090/myshop/images/cherry1.jpg');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
