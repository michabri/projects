<%-- 
    Document   : Forums
    Created on : May 5, 2016, 6:04:06 PM
    Author     : Micha
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
       <body bgcolor="black">
        <font face="algerian" color="white" size="10">
            Luxury Edition
        </font>
        <font face="algerian" color="white" size="4">
            <i>The World's Lucrative Marketplace</i> 
        </font>
        <%
            if (session.getAttribute("SignedIn") != null) {
        %>
         <div style="float: right">
            <font color="white">You are logged in as a <% out.print(session.getAttribute("SignedIn")); %></font>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <a href ="logout.jsp"><font color="white">Log Out</font></a>
        </div>
        <% 
            } 
        %>        
        <hr color="white">
        <div class="relative">
            
            <table border="4" cellpadding="10" style="margin-top:0px; margin-left:275px;">
                <tr>
                    <td>
                        <font face="garamond" color="white" size="5">
                            <u><a href='NewCarsEx.jsp'><font color="#FFFFFF">Top 10 cars</font></a></u>
                        </font>
                    </td>
                    <td>
                        <font face="garamond" color="white" size="5">
                       <u><a href='Forums.jsp'><font color="#FFFFFF">Forums</font></a></u>
                        </font>
                    </td>
                    <td>
                        <font face="garamond" color="white" size="5">
                          <u><a href='AboutSite.jsp'><font color="#FFFFFF">About</font></a></u>
                        </font>
                    </td>
                    <td>
                        <font face="garamond" color="white" size="5">
                            <u><a href='SignUpOrLogin.jsp'><font color="#FFFFFF">Sign up or Login </font></a></u>
                        </font>
                    </td>
                    <td>
                        <font face="garamond" color="white" size="5">
                            <u><a href="http://localhost:8080/LuxuryCarsProj/NewGallery.jsp"><font color="#FFFFFF">Gallery</font></a></u>
                        </font>
                    </td>
                    <td>
                        <form action="search.html" method="GET">
                            <input type="text" name="q" placeholder="Search LuxuryEdition"/>
                            <input type="submit" value="Search"/>
                        </form>
                    </td>
                </tr>
            </table>
        </div>
        <br>
       <center>
           <font size="6" color="white">
           <a href="http://www.telegraph.co.uk/cars/gallery/the-10-best-cars-in-the-world/">Car forum!</a>
           <br>
           <a href="https://www.youtube.com/user/MotorTrend">Race videos!</a>
           </font>
       </center>
    </body>
</html>
