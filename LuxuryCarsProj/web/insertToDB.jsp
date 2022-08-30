<%-- 
    Document   : insertToDB
    Created on : Apr 16, 2016, 4:03:08 PM
    Author     : Micha
--%>
<%@page import="MyClasses.MyUtils"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%
    request.setCharacterEncoding("UTF-8");       //o קידוד לעברית
    // קבלת ערכי השדות מצד לקוח לצד שרת

    String first             = request.getParameter("first");
    String Email             = request.getParameter("Email");
    String pass1             = request.getParameter("pass1");
    String adress1           = request.getParameter("adress1");
    String adress2           = request.getParameter("adress2");
    String city              = request.getParameter("city");
    String FamilyCars        = request.getParameter("FamilyCars");
    String CompactCars       = request.getParameter("CompactCars");
    String MidSizeCars       = request.getParameter("MidSizeCars");
    String FullSizeCars      = request.getParameter("FullSizeCars");
    String Update            = request.getParameter("Update");
    String Delete            = request.getParameter("Delete");
    

    //O שלב שני - קישור למסד הנתונים
    String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
    Connection con    = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                

    Statement stmt;
    stmt = con.createStatement();

    Boolean isInsert = false;
    Boolean isUpdate = false;
    Boolean isDelete = false;
    if((Update == null)&&(Delete == null))
        isInsert = true;
    else if(Update == null)
        isDelete = true;
    else if(Delete == null)
        isUpdate = true;
    
    
    if(FamilyCars==null)
        FamilyCars= "";
    if(CompactCars==null)
        CompactCars= "";
    if(MidSizeCars==null)
        MidSizeCars= "";
    if(FullSizeCars==null)
        FullSizeCars= "";

    if (isInsert)
    {
        if(first == null)
            return;
        ////o יצירת שאילתת בחירה למסד לצורך בדיקת קיום המשתמש
        String sql = "SELECT * FROM users WHERE first='" + first + "'";
        ResultSet rs = stmt.executeQuery(sql);
        ////if user exists and update checked
        if(rs.next())
        {
            out.println("<body bgcolor='black'><center><h3><font color='white'>User already exists</h3></font></center><br>");
            out.print  ("<center><br><a href='SignUpOrLogin.jsp'><font color='white'>Back to Signup or Login form</font></a></center>"); 
        } 
        else
        {
            
          sql = "INSERT INTO users VALUES ('"
            + first + "','" +  Email +"','"+ pass1 +"','"+ adress1 +
            "','" + adress2 + "','"+ city + "','"+ FamilyCars + "','"  
            + CompactCars + "','" + MidSizeCars + "','" + FullSizeCars + "')";
          stmt.executeUpdate(sql);
          out.print("<body bgcolor='black'>");
          out.print("<center><h3><font color='white'>User " + first 
                     +" <br/>signed up successfully</font></h3></center><br>");
          out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'><font color='white'>Back to Singup or Login form</font></a></center>");  
        }
    }
    else if (isUpdate)
    {
               String sqlStr = "UPDATE users SET Email='" + Email 
                    +"',city='" + city 
                    +"',adress1='" + adress1 
                    +"',adress2='" + adress2 
                    + "',FamilyCars='" + FamilyCars
                    + "',CompactCars='" + CompactCars 
                    + "',MidSizeCars='" + MidSizeCars 
                    + "',FullSizeCars='" + FullSizeCars 
                    + "' WHERE first='"+ first +"'";
          stmt.executeUpdate(sqlStr);        
          out.print("<body bgcolor='black'>");
          out.print("<center><h3><font color='white'>User " + first+ " updated successfully</font></h3></center><br>");
          out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'><font color='white'>Back to Singup or Login form</font></a></center>");  

    }
    else if (isDelete)
    {
        String sqlStr = "DELETE FROM users WHERE first='"+ first +"'";
        stmt.executeUpdate(sqlStr);
        out.print("<body bgcolor='black'>");
        out.print("<center><h3><font color='white'>User " + first+ " deleted successfully</font></h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'><font color='white'>Back to Singup or Login form</font></a></center>");          
    }

    stmt.close();
    con.close();
%>
