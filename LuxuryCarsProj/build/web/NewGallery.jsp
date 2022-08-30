<html>
    <head>
        <title>Gallery</title>
        <script type="text/javascript">
            var i=2;
            function next()
            {
                picture.src="pic/"+i+".jpg";
                i++;
                if(i==10)
                    i=1;

            }
            function back()
            {
                picture.src="pic/"+i+".jpg";
                i--;
                if(i==0)
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
                            <u><a href="NewGallery.jsp"><font color="#FFFFFF">Gallery</font></a></u>
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
        <center>
            <font face="algerian" color="white" size="10">
        Gallery
        </font>
            <br>
            <a href="MainMenu.jsp"><font face="algerian" color="white" size="5">Back to Main menu</font></a>
            <br>   <br> <br>
            <img id="picture" src="pic/1.jpg" alt="" width="400px" height="400px"/> <br><br><br>
            <input type="submit" value="back" onclick="back()"/> &nbsp&nbsp
            <input type="submit" value="next" onclick="next()"/>
        </center>
         <br><br>
    </body>
</html>
