
<%@page import="MyClasses.MyUtils"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>basic form</title>
    </head>
    <body>
      <%
         application.setAttribute("siteCounter", 0);
         response.sendRedirect("MainMenu.jsp");
      %>
    </body>
</html>
