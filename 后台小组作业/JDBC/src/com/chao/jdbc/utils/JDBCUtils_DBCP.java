package com.chao.jdbc.utils;

import org.apache.commons.dbcp2.BasicDataSource;
import org.apache.commons.dbcp2.BasicDataSourceFactory;

import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JDBCUtils_DBCP {

    private static BasicDataSource dataSource = null;

    static{
        try{
            InputStream in = JDBCUtils_DBCP.class.getClassLoader().getResourceAsStream("dbcpconfig.properties");
            Properties properties = new Properties();
            properties.load(in);

            dataSource = BasicDataSourceFactory.createDataSource(properties);


        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static Connection getConnection() throws SQLException {
        return dataSource.getConnection();
    }
    
    public static void release(Connection conn, Statement st, ResultSet rs){
        if(rs != null){
            try{
                rs.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
            try{
                st.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
            try{
                conn.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }
}
