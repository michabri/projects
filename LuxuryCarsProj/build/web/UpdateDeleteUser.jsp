<%-- 
    Document   : UpdateDeleteUser
    Created on : Apr 16, 2016, 4:03:08 PM
    Author     : Micha
--%>

<%@page import="MyClasses.MyUtils"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title></title>
    <script type="text/javascript">            
        function checkForm()
        {
            return true;
        }
         function goBack() 
            {
                var i=0;
                while(i<2)
                {
                window.history.back();
                i++;
                }   
            }
    </script>
</head> 

<body bgcolor='black'>
    <br><br>
     
        <%
            request.setCharacterEncoding("UTF-8");
            String name = request.getParameter("first");
            
            String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
            Connection con = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                

            Statement stmt;
            stmt = con.createStatement();

            String sql = "SELECT * FROM users WHERE first = '" + name + "' ";
            ResultSet rs = stmt.executeQuery(sql);
            if(rs.next())
            {
        %>        
        <center><b><h3><u><font color="white">User details</font></u></h3></b></center>
        <br>
        <form name="UserDetails" method="get" onsubmit="return checkForm()" action="insertToDB.jsp">
            <table width="60%" align="center" border="3" bgcolor="pink">
                <tr>
                    <td><font size="3" >Name</font></td>
                    <td><input type="text" name="first" readonly value='<%=rs.getString("first")%>'></td>
                </tr>
                <tr>
                    <td><font size="3" >Email</font></td>                                        
                    <td><input type="text" name="Email" value='<%=rs.getString("Email")%>'></td>
                </tr>
                <tr>
                    <td><font size="3" >Address</font></td>
                    <td><input type="text" name="adress1" value='<%=rs.getString("adress1")%>'></td>                    
                </tr>
                <tr>
                    <td><font size="3" >Address cont.</font></td>
                    <td><input type="text" name="adress2" value='<%=rs.getString("adress2")%>'></td>                    
                </tr>
                <tr>
                    <td><font size="3" >City</font></td>
                    <td><input type="text" name="city" value='<%=rs.getString("city")%>'></td>
                </tr>

                <tr>
                    <td><font size="3" >Car</font></td>
                    <td>                    
                    <%
                     String cb1 = rs.getString("FamilyCars");
                     String cb2 = rs.getString("CompactCars");
                     String cb3 = rs.getString("MidSizeCars");
                     String cb4 = rs.getString("FullSizeCars");
                     String cb5 ;//= rs.getString("RaceCars");
                     String cb6 ;//= rs.getString("SportsCars");
                     String cb7 ;//= rs.getString("LuxuryCars");
                     if(!cb1.isEmpty())
                     {
                    %>
                        <font size="3">Family Cars</font>
                        <input type="checkbox" name="FamilyCars" value="FamilyCars" checked/>                        
                    <%
                     }
                     else
                     {
                    %>
                        <font size="3" >Family Cars</font>
                        <input type="checkbox" name="FamilyCars" value=""/>
                     <%
                     }
                     if(!cb2.isEmpty())
                     {
                    %>
                        <font size="3" >Compact Cars</font>
                        <input type="checkbox" name="CompactCars" value="Compact Cars" checked/>                       
                    <%
                     }
                     else
                     {
                    %>
                        <font size="3" >Compact Cars</font>
                        <input type="checkbox" name="CompactCars" value=""/>
                     <%
                     }
                     if(!cb3.isEmpty())
                     {
                    %>
                        <font size="3" >MidSize Cars</font>
                        <input type="checkbox" name="MidSizeCars" value="MidSize Cars" checked/>                       
                    <%
                     }
                     else
                     {
                    %>
                        <font size="3" >MidSize Cars</font>
                        <input type="checkbox" name="MidSizeCars" value="MidSize Cars"/>
                     <%
                     }
                     if(!cb4.isEmpty())
                     {
                    %>
                        <font size="3" >FullSize Cars</font>
                        <input type="checkbox" name="FullSizeCars" value="FullSize Cars" checked/>
                    <%
                     }
                     else
                     {
                    %>
                        <font size="3" >FullSize Cars</font>
                        <input type="checkbox" name="FullSizeCars" value="FullSize Cars"/>                        
                     <%
                     }
                     
                    %>
                    </td>
                </tr>
                <tr>
                <td></td>
                <td>
                &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
                <input type="submit" name="Delete" value="Delete">
                &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
                <input type="submit" name="Update" value="Update">                    
                </td></tr>                    
            </table>
            <br>
            <center><font size="7" color="white"><u><button onclick="goBack()">
                            <%if(name.equals("Admin")){%>
                            Administrator Menu
                            <%}else{%>
                            Go Back
                            <%}%>
            </button></u></font></center>
        <%           
        } 
        else
        {
            out.println("<br><br><br><br><center><b><font size='5' color='red'>User does not exist</font></b></center><br><br><br><br/><br><br><br><br><br><br>");
            out.print("<center><font size='7' color='white'><u><button onclick='goBack()'>");
            if(name.equals("Admin")){
                out.print("Administrator Menu");
            }else{
                out.print("Go Back");
            }
            out.print("</button></u></font></center>");
        }
        %>
        <br>
        </form>
    </body>
</html>
