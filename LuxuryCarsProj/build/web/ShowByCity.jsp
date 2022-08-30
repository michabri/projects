<%-- 
    Document   : ShowByCity
    Created on : May 4, 2016, 8:12:12 PM
    Author     : Micha
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <script type="text/javascript">
            function checkForm()
            {
                 if(document.tofes.city.selectedIndex===0)
                {
                    window.alert("pick one");
                    return false;
                }
                return true;
            }
            function goBack() 
            {
                window.history.back();
            }
        </script>
    </head>
    <body>
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
            <font color="white">You are logged in as a <% out.print(session.getAttribute("SignedIn"));%></font>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <a href ="logout.jsp"><font color="white">Log Out</font></a>
        </div>
        <% 
            } 
        %>        
        <hr color="white">
        <table border="4" cellpadding="10" style="margin-top:0px; margin-left:275px; border-color:white;">
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
                    <a href=http://localhost:8080/LuxuryCarsProj/index.jsp><font color="#FFFFFF">Main Menu</font></a>
                    </font>
                </td>
                <td>
                    <font face="garamond" color="white" size="5">
                    <a href="http://localhost:8080/LuxuryCarsProj/NewGallery.jsp"><font color="#FFFFFF">Gallery</font></a>
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
        <br><br><br>
      <center><table bgcolor="white" cellpadding="10" border="1">
            <tr>
                <td>
                    <form name="tofes" method="get" onsubmit="return checkForm()" action="ShowUsersByCity.jsp">
                         <select name="city" id="cityId">
                             <option>city</option>
                             <option>Jerusalem</option>
                             <option>Tel-Aviv</option>
                             <option>Haifa</option>
                             <option>Baar-Sheva</option>
                             <option>Ashkelon</option>
                             <option>Else</option>
                         </select>
                        <br>
                        <input type="submit" value="send" />
                    </form>
                </td>
            </tr>
          </table></center>
      <br>
      <center><font size="7" color="white"><u><button onclick="goBack()">Administrator Menu</button></u></font></center>
    </body>
</html>
