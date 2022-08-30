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
    <center><b><h3><u><font color="white">User details</font></u></h3></b></center><br>
     <table width="60%" align="center" border="3" bgcolor="pink">
                <tr>
                    <th><font size="3" >Name</font></th><th><font size="3" >Email</font></th><th><font size="3" >Address</font></th>
                    <th><font size="3" >Address number</font></th><th><font size="3" >City</font></th><th><font size="3">Family cars</font></th>
                    <th> <font size="3" >Compact Cars</font></th><th><font size="3" >MidSize Cars</font></th><th><font size="3" >FullSize Cars</font></th>
                </tr>
        <%
            request.setCharacterEncoding("UTF-8");            
            String favCars = request.getParameter("FavCars");
            
            String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
            Connection con = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                

            Statement stmt;
            stmt = con.createStatement();

            String sqlQueryParam = "";
            if(favCars.equals("Family Cars"))
            {
                sqlQueryParam = "WHERE FamilyCars <> ''";
            }
            else if (favCars.equals("Compact Cars"))
            {
                sqlQueryParam = "WHERE CompactCars <> ''";            
            }
            else if (favCars.equals("Mid-size Cars"))
            {
                sqlQueryParam = "WHERE MidSizeCars <> ''";                
            }    
            else if (favCars.equals("Full-size Cars"))
            {
                sqlQueryParam = "WHERE FullSizeCars <> ''";
            }
            String sql = "SELECT * FROM users " + sqlQueryParam;
            ResultSet rs = stmt.executeQuery(sql);
            String cb1 = "";
            String cb2 = "";
            String cb3 = "";
            String cb4 = "";
            while(rs.next())
            {
                %>       
                <tr> 
                    <td><%=rs.getString("first")%></td>
                    <td><%=rs.getString("Email")%></td>
                    <td><%=rs.getString("adress1")%></td>
                    <td><%=rs.getString("adress2")%></td>
                    <td><%=rs.getString("city")%></td>                   
                    <%
                     cb1 = rs.getString("FamilyCars");
                     cb2 = rs.getString("CompactCars");
                     cb3 = rs.getString("MidSizeCars");
                     cb4 = rs.getString("FullSizeCars");
                     if(cb1!= null && !cb1.isEmpty())
                     {
                    %>
                    <td><font size="3">Family Cars</font></td>                        
                    <%
                     }
                     else
                     {
                    %>
                    <td><font size="3">-</font></td>
                     <%
                     }
                     if(cb2!= null && !cb2.isEmpty())
                     {
                    %>
                    <td><font size="3" >Compact Cars</font></td>
                        
                    <%
                     }
                     else
                     {
                    %>
                         <td><font size="3">-</font></td>
                     <%
                     }
                     if(cb3!= null && !cb3.isEmpty())
                     {
                    %>
                         <td><font size="3" >MidSize Cars</font></td>                      
                    <%
                     }
                     else
                     {
                    %>
                       <td><font size="3">-</font></td>
                     <%
                     }
                     if(cb4!= null && !cb4.isEmpty())
                     {
                    %>
                       <td><font size="3" >FullSize Cars</font></td>
                    <%
                     }
                     else
                     {
                    %>
                         <td><font size="3">-</font></td>                       
                     <%
                     }
                     
                    %>
                </tr>  
        <%           
        }             
        %>
        </table>
        <br>
        <br>
      <center><font size="7" color="white"><u><button onclick="goBack()">Administrator Menu</button></u></font></center>
    </body>
</html>