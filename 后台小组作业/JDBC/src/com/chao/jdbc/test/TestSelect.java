package com.chao.jdbc.test;

import com.chao.jdbc.utils.jdbcUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class TestSelect {
    public static void main(String[] args) {
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;
        try{
            conn = jdbcUtils.getConnection();
            st = conn.createStatement();
            String sql = "select * from users where id = 2";
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
