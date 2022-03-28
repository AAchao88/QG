package com.chao.jdbc.test;

import com.chao.jdbc.utils.jdbcUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class TestInsert {
    public static void main(String[] args) {


        Connection conn =null;
        Statement st = null;
        ResultSet rs = null;
        try{
            conn = jdbcUtils.getConnection();
            st = conn.createStatement();
            String sql = "INSERT INTO users(id,`NAME`,`PASSWORD`,`email`,`birthday`)" +
                    "VALUES(5,'chaoshen','123456','2345@qq.com','2020-11-2')";
            int i = st.executeUpdate(sql);
            if(i>0){
                System.out.println("插入成功！");
            }
        }catch (SQLException e){
            e.printStackTrace();
        }finally{
            jdbcUtils.release(conn,st,rs);
        }
    }
}
