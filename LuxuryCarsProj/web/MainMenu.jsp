<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    "http://www.w3.org/TR/html4/loose.dtd">
<html>
    <head>
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
        <script>
            var imageIndex = 1;
            function setImage()
            {
                slideShow.src = "img/slideShow/" + imageIndex + ".jpg";
                imageIndex++;
                if (imageIndex >= 4)
                    imageIndex = 1;
            }
            function startInterval()
            {
                var intrev = setInterval('setImage()', 2000);
            }
        </script>
    </head>

    <body bgcolor="black">
        <script type="text/javascript" >startInterval();</script>
        <font face="algerian" color="white" size="10">
            Luxury Edition
        </font>
        <font face="algerian" color="white" size="4">
            <i>The World's Lucrative Marketplace</i> 
        </font>        
        <%
            int i = Integer.parseInt(application.getAttribute("siteCounter").toString());
            i++;
            application.setAttribute("siteCounter", i);
            if (session.getAttribute("SignedIn") != null) {
        %>
        <div style="float: right">
            <font color="white"><b>Visitors <% out.println(i);%></b> &nbsp;&nbsp;&nbsp;&nbsp;
                You are logged in as a <% out.print(session.getAttribute("SignedIn")); %></font>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <a href ="logout.jsp"><font color="white">Log Out</font></a>
        </div>
        <% 
            } 
        %>
        <hr color="white">
        <div class="container">
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
        <br>
        <table bgcolor="black" style="margin-top:0px; margin-left:320px;">          
            <tr>
                <td style="float: right;margin-right: 35px;">
                    <br/><br/></br>
                    <img style="margin-right: 35px;" id="slideShow" src="img/slideShow/3.jpg" width="300" height="350"/>

                </td>
                <td>
                    <center style="margin-right: 30px;margin-bottom: 160px;">
                        <br/>
                        <iframe width="350" height="450" src="https://www.youtube.com/embed/gp3ZKiwZMvg" frameborder="0" autoplay="1"></iframe>                        
                    </center>
                </td>
            </tr>
        </table>
    </body>
</html>