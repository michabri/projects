package MyClasses;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.servlet.ServletContext;

public class MyUtils
{
    private static String errorText;
    public static String getErrorText()
    {
        return errorText;
    }
    public static Connection getSiteDBconnectionWithJdbcOdbcDriver(String fullDbPath)
    {
        Connection con = null;
        
        try
        {
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            String url = "jdbc:odbc:Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=" + fullDbPath;           
            con = DriverManager.getConnection(url,"","");
        }
        catch(Exception ex)
        {
            System.err.println(ex);
            errorText = ex.toString();
        }

        return con;
    }

    public static String getDBPath(ServletContext app, String dbPath)
    {
        String fullDbPath = app.getRealPath("\\");
        if(fullDbPath.indexOf("build") > 0)
        {
            fullDbPath = fullDbPath.substring(0, fullDbPath.indexOf("build"));
            fullDbPath = fullDbPath + "web\\"+dbPath;
        }
        else
        {
            fullDbPath = fullDbPath + dbPath;
        }
        return fullDbPath;
    }
    public static void main(String[] args) {
        getSiteDBconnectionWithJdbcOdbcDriver("C:\\Users\\Micha\\Documents\\NetBeansProjects\\LuxuryCarsProj\\web\\db\\siteDB.mdb");
    }
}
