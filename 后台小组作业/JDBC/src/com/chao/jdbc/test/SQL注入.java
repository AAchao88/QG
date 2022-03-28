package com.chao.jdbc.test;

import com.chao.jdbc.utils.jdbcUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class SQL注入 {
    public static void main(String[] args) {
        login("'or'1=1","123456");
    }

    public static void login(String username,String password){
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;
        try{
            conn = jdbcUtils.getConnection();
            st = conn.createStatement();
            String sql = "SELECT * FROM users WHERE `name` = '"+username+"' AND `password` = '"+password+"'";
            rs = st.executeQuery(sql);
            while(rs.next()){
                System.out.println(rs.getString("NAME"));

            }
        }catch (SQLException e){
            e.printStackTrace();
        }finally{
            jdbcUtils.release(conn,st,rs);
        }
    }

}
