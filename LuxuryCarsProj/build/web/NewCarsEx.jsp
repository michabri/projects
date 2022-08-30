<%-- 
    Document   : NewCarsEx
    Created on : May 5, 2016, 3:52:53 PM
    Author     : Micha
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <style type="text/css">
            .myspan 
            {
                color: white;
            }  
            .div2 
            {
                float:right;
                text-align: right;
            }
        </style>
        <link rel="stylesheet" type="text/css" href="css/main.css">
        <script type="text/javascript">
            var i=2;
            function next()
            {
                picture.src="pict2/"+i+".jpg";
                i++;
                if(i===10)
                    i=1;

            }
            function back()
            {
                picture.src="pict2/"+i+".jpg";
                i--;
                if(i===0)
                    i=10;

            }
        </script>
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
        
        <center><font color="white"><u><h1>Top 10 most luxurious cars in the world </h1></u></font></center>
            <table border = "1" bgcolor="white" style="margin-top:0px; margin-left:270px;">
                <tr>
                    <td><font size="3">Rank</font></td>
                    <td><font size="3">Name</font></td>
                    <td><font size="3">cost</font></td>
                </tr>
                <tr>
                    <td><font size="3">1</font></td>
                    <td><font size="3">Koenigsegg CCXR Trevita</font></td>
                    <td><font size="3">$4.8 million</font></td>
                </tr>
                <tr>
                    <td><font size="3">2</font></td>
                    <td><font size="3">Lamborghini Veneno</font></td>
                    <td><font size="3">$4.5 million</font></td>
                </tr>
                
                <tr>
                    <td><font size="3">3</font></td>
                    <td><font size="3">W Motors Lykan Hypersport</font></td>
                    <td><font size="3">$3.4 million </font></td>
                </tr>
                
                <tr>
                    <td><font size="3">4</font></td>
                    <td><font size="3">Limited Edition Bugatti Veyron by Mansory Vivere</font></td>
                    <td><font size="3">$3.4 million</font></td>
                </tr>
                
                
                <tr>
                    <td><font size="3">5</font></td>
                    <td><font size="3">Pagani Huayra BC</font></td>
                    <td><font size="3">$2.6 million</font></td>
                </tr>
                
                <tr>
                    <td><font size="3">6</font></td>
                    <td><font size="3">Ferrari F60 America</font></td>
                    <td><font size="3">$2.5 million</font></td>
                </tr>
                
                <tr>
                    <td><font size="3">7</font></td>
                    <td><font size="3">Bugatti Chiron</font></td>
                    <td><font size="3">$2.5 million</font></td>
                </tr>
                
                <tr>
                    <td><font size="3">8</font></td>
                    <td><font size="3">Koenigsegg One:1</font></td>
                    <td><font size="3">$2 million</font></td>
                </tr>
                
                <tr>
                    <td><font size="3">9</font></td>
                    <td><font size="3">Koenigsegg Regera</font></td>
                    <td><font size="3">$2 million</font></td>
                </tr>
                
                
                <tr>
                    <td><font size="3">10</font></td>
                    <td><font size="3">Lamborghini Centenario LP 770-4</font></td>
                    <td><font size="3">$1.9 million</font></td>
                </tr>
            </table>
         <table border = "1" bgcolor="white" style="margin-top:-270px; margin-left:800px;">
             <tr>
                 <td>
                    <img id="picture" src="pict2/1.jpg" alt="" width="350px" height="350px"/> <br><br><br>
                    <input type="submit" value="back" onclick="back()"/>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <input type="submit" value="next" onclick="next()"/>
                <tr>
                 </td>
             </tr>
    </body>
</html>
