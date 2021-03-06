package com.chao.jdbc.test;

import java.sql.*;

public class jdbcFirstDemo {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        //1.加载驱动
        Class.forName("com.mysql.jdbc.Driver");

        //2.用户信息和url
        String url = "jdbc:mysql://localhost:3306/jdbcstudy?useUnicode=true&characterEncoding=utf8&useSSL=false";
        String username = "root";
        String password = "123456";

        //3.连接成功，数据库对象 connection 代表数据库
        Connection connection = DriverManager.getConnection(url,username,password);

        //4.执行SQL的对象 Statement 执行SQL的对象
        Statement statement = connection.createStatement();

        //5.执行SQL的对象去执行SQL，可能存在结果，查看返回结果
        String sql = "SELECT * FROM users";
        ResultSet resultSet = statement.executeQuery(sql);
        while(resultSet.next()){
            System.out.println("id="+resultSet.getObject("id"));
            System.out.println("NAME="+resultSet.getObject("NAME"));
            System.out.println("PASSWORD="+resultSet.getObject("PASSWORD"));
            System.out.println("email="+resultSet.getObject("email"));
            System.out.println("birthday="+resultSet.getObject("birthday"));
        }


        //释放连接
        resultSet.close();
        statement.close();
        connection.close();

    }

}
