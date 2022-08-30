<html>
    <head>
        <title>Main Page</title>
        
    </head>
    
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
        </div >
        <div class="relative2">
            <table bgcolor="white" cellpadding="10" border="1">
                <tr>
                    <td>
                    <font face="algerian" color="black" size="5">
                    <u>Sign Up Document</u>
                    </font>
                    <br>
                    <br>
                    <form name="tofes" method="get" onsubmit="return CheckForm()" action="insertToDB.jsp">    
                    <font face="arial" color="black" size="3">
                        <u>Account Name:</u>
                         </font>
                          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          <input type="text" name="first" maxlength="10">
                         <br>
                         <font face="arial" color="black" size="3">
                         <u>Email:</u>
                         </font>
                          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          &nbsp;&nbsp;&nbsp;
                         <font face="arial" color="black" size="3">
                         <input type="text" name="Email" >
                         <br>
                         <u>Password</u>
                         </font>
                          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                          <font face="arial" color="black" size="3">
                          <input type="password" name="pass1" >
                         <br>
                         <u>Confirm Password</u>
                         </font>

                         <input type="password" name="pass2">
                         <br>
                         <br>
                         <font face="arial" color="black" size="3">
                         <u>Adress</u>
                         </font>
                         <br>
                          <font face="arial" color="black" size="3">
                         <u>Street Name: </u> &nbsp; &nbsp; 
                         </font>
                         <input type="text" name="adress1" >
                         <br>
                          <font face="arial" color="black" size="3">
                         <u>House Number:</u>
                         </font>
                         <input type="text" name="adress2">
                         <br>
                         <font face="arial" color="black" size="3">
                           <u>City:</u>
                         </font>
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
                         <br>
                         <font face="arial" color="black" size="3">
                         <u>Type of cars you like:</u>
                         </font>
                         <br>
                        family Cars
                        <input type="checkbox" name="FamilyCars" value="Family Cars">
                         &nbsp;
                        Compact Cars
                        <input type="checkbox" name="CompactCars" value="Compact Cars">
                         <br>
                         Mid-size Cars
                         <input type="checkbox" name="MidSizeCars" value="Mid-size Cars" >
                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                         Full-size Cars
                         <input type="checkbox" name="FullSizeCars" value="Full-size Cars">
                         <br>
                         <u>Special Requests</u>
                         <br>
                         <textarea cols="50" rows="5" name="special"></textarea>
                         <br>
                         <br>
                         <br>
                         <input type="submit" name="Insert" value="send">
                         &nbsp;&nbsp;
                         <!--<input type="reset" value="reset">-->
                    </form>
                    </td>
                    <td>
                        <img src="http://cdn.luxedb.com/wp-content/uploads/2011/03/McLaren-MP4-12C-luxury-cars-2.jpg" width="500" height="500">
                    </td>
                    <td>
                        <font face="algerian" color="black" size="4">
                        <b><u>___________________________</u></b>
                    </font>
                     <br><br><br><br>
                        <font face="algerian" color="black" size="5">
                    <u>Log-In Document</u>
                    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;<u>User/Admin</u>
                    </font>
                    <br><br><br>
                    
                    <form name="LogIn" method="get" action="FindUserInDB.jsp">
                        <font face="garamond" color="black" size="4"><u>Username:</u></font>
                        <input type="text" name="first">
                        <br><br>
                        <font face="garamond" color="black" size="4"><u>Password:</u></font>
                        <input type="password" name="pass1">
                        <br>
                        <br>
                        <input type="submit" value="Log In">    
                    </form>
                    <br><br>                    
                    <font face="algerian" color="black" size="4">
                     <b><u>___________________________</u></b>
                    </font>
                    </td>
                </tr>
            </table>
        </div>
        <script type='text/javascript'>
            function CheckForm()
            {
                var letters = /^[A-Za-z]+$/;
                var reg = /^[0-9]+$/;
               
                if(document.tofes.first.value.length<=1)
                {
                    window.alert("The name must be more than 1 letter");                    
                    return false;
                }
                if(!(document.tofes.first.value.match(letters)))  
                {  
                   window.alert("Please input alphanumeric characters only"); 
                   return false;
                }
                if(!(document.tofes.first.value[0] === document.tofes.first.value[0].toUpperCase()))
                {   
                   alert("First letter must be big");
                   return false;                  
                } 
                if(document.tofes.Email.value.length < 6)
                {
                    window.alert("Too short email");
                    return false;
                }
                if(document.tofes.Email.value.indexOf("@")<0 || document.tofes.Email.value.indexOf(".com")<0)
                {
                    window.alert("The email must be real");
                    return false;    
                }
                if(document.tofes.pass1.value.length<5)
                {
                    window.alert("The password must be more than 5 letters");   
                    return false;                        
                } 
                if(!(document.tofes.pass2.value === document.tofes.pass1.value))
                {
                    window.alert("The passwords must match");
                    return false;                        
                }
                if(document.tofes.adress1.value.length<2)
                {
                    window.alert("Please enter a real street name");
                  return false;                        
                }

                if(!(document.tofes.adress2.value.match(reg)))
                {
                    window.alert("please enter a number");
                    return false;                         
                }
                //window.alert("!!!" + document.getElementById("cityId").value.selectedIndex);
                if(document.tofes.city.selectedIndex===0)
                {
                    window.alert("pick one");
                    return false;
                }
                var x=0;
                if(document.tofes.FamilyCars.checked===true)
                {
                    x++;
                }
                if(document.tofes.CompactCars.checked===true)
                {
                    x++;
                }
                if(document.tofes.MidSizeCars.checked===true)
                {
                    x++;
                }
                if(document.tofes.FullSizeCars.checked===true)
                {
                    x++;
                }
                if(x<1)
                {
                    window.alert("pick atleast 1");
                    return false;
                }
                window.alert("Thank you for signing!!");
                return true;                
            }
        </script>
    </body>
</html>
