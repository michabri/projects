<%@page import="MyClasses.MyUtils"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
<style>
    a {
    color: white;
}
</style>
        
<%
    request.setCharacterEncoding("UTF-8");       //o קידוד לעברית
    // קבלת ערכי השדות מצד לקוח לצד שרת           
    String name = request.getParameter("first");
    String password = request.getParameter("pass1");
    if (name == null || name == "")
    {
        out.println("<body bgcolor='black'><center><h3><font color='white'>User doesn't exist in the system</font></h3></center><br>");
        out.print("<center><br><a href='SignUpOrLogin.jsp'><font color='white'>Back to Sign up or Login form</font></a></center>");
        return;
    }
    else
    {
       name = name.substring(0, 1).toUpperCase() + name.substring(1);
    }
    String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
    Connection con    = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                
    
    Statement stmt;
    stmt = con.createStatement();

    String sql = "SELECT * FROM users WHERE first='" + name + "'";
    ResultSet rs = stmt.executeQuery(sql);
    if(!rs.next())
    {
        out.println("<body bgcolor='black'><center><h3><font color='white'>User doesn't exist in the system</font></h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'><font color='white'>Back to Sign up or Login page</font></a></center>");     
    }
    else if (!(rs.getString("pass1").equals(password)))
    {
        out.println("<body bgcolor='black'>"+"<center><h3><font color='white'>User doesn't exist in the system</font></h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'><font color='white'>Back to Signup or Login form</font></a></center>");        
    }
    else
    {
        out.println("<form action='UpdateDeleteUser.jsp'>");
        session.setAttribute("SignedIn", name);
        if(rs.getString("first").equals("Admin"))
        {
%>
        <body bgcolor='black'>
        <font face='algerian' color='white' size='10'>Luxury Edition</font>
        <font face='algerian' color='white' size='4'><i>The World's Lucrative Marketplace</i></font>
<%
            if (session.getAttribute("SignedIn") != null) {
%>
         <div style="float: right">
            <font color="white">You are logged in as a <% out.print(session.getAttribute("SignedIn"));%></font>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <a href ="logout.jsp"><font color="white">Log Out</font></a>
        </div>
<% 
            } 
%>
        <hr color='white'>
        <center><h1><font color='white'>Administrator Menu</h1></font></center>
        <center><font size='5'><a href='UpdateUser.jsp'>Update user Or Delete</a></font>&nbsp;&nbsp;<font color='white' size ='7'>|</font>&nbsp;&nbsp;<a href='ShowUsers.jsp'><font size='5'>Show users</font></a>&nbsp;&nbsp;<font color='white' size ='7'>|</font>&nbsp;&nbsp;<a href='ShowByCity.jsp'><font size='5'>Show users by city</font></a>&nbsp;&nbsp;<font color='white' size ='7'>|</font>&nbsp;&nbsp;<a href='ShowFavCar.jsp'><font size='5'>Show users by favorite car</font></a></center>
        <center><br>"+"<font color='white' size='5'><a href='SignUpOrLogin.jsp'>Back to Sign up or Login page</a></font></center>
<%
        }
        else
        {
            out.print("<body bgcolor='black'><center></br><font color='white' size='5'>Confirm loading details for user<font></br></br>");
            out.print("<input type='text' name='first' readonly value='" + name +"'></br></br><input type='submit' value='Confirm'><center></body>");
        }
    }       
%>
