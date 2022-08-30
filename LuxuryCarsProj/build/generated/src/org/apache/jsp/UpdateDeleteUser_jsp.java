package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import MyClasses.MyUtils;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Connection;

public final class UpdateDeleteUser_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n");
      out.write("   \"http://www.w3.org/TR/html4/loose.dtd\">\n");
      out.write("<head>\n");
      out.write("    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("    <title></title>\n");
      out.write("    <script type=\"text/javascript\">            \n");
      out.write("        function checkForm()\n");
      out.write("        {\n");
      out.write("            return true;\n");
      out.write("        }\n");
      out.write("    </script>\n");
      out.write("</head> \n");
      out.write("\n");
      out.write("<body dir=\"rtl\">\n");
      out.write("    <br><br>\n");
      out.write("     <center><b><h3><u>User details</u></h3></b></center><br>\n");
      out.write("        ");

            request.setCharacterEncoding("UTF-8");
            String name = request.getParameter("first");
            if((name == null) || (name != null && name.equals("")))
            {
                name="Admin";
            }
            
            String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
            Connection con = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                

            Statement stmt;
            stmt = con.createStatement();

            String sql = "SELECT * FROM users WHERE first='" + name + "'";
            ResultSet rs = stmt.executeQuery(sql);
            if(rs.next())
            {
        
      out.write("        \n");
      out.write("        <form name=\"UserDetails\" method=\"get\" onsubmit=\"return checkForm()\" action=\"insertToDB.jsp\">\n");
      out.write("            <table width=\"60%\" align=\"center\" border=\"3\" bgcolor=\"pink\">\n");
      out.write("                <tr>\n");
      out.write("                    <td><input type=\"text\" name=\"first\" readonly value='");
      out.print(rs.getString("first"));
      out.write("'></td>\n");
      out.write("                    <td><font size=\"3\" >Name</font></td>\n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td><input type=\"text\" name=\"Email\" value='");
      out.print(rs.getString("Email"));
      out.write("'></td>\n");
      out.write("                    <td><font size=\"3\" >Email</font></td>                    \n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td><input type=\"text\" name=\"Address\" value='");
      out.print(rs.getString("adress1"));
      out.write("'></td>\n");
      out.write("                    <td><font size=\"3\" >Address</font></td>\n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td><input type=\"text\" name=\"Address2\" value='");
      out.print(rs.getString("adress2"));
      out.write("'></td>\n");
      out.write("                    <td><font size=\"3\" >Address cont.</font></td>\n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td><input type=\"text\" name=\"duel\" value='");
      out.print(rs.getString("city"));
      out.write("'></td>\n");
      out.write("                    <td><font size=\"3\" >City</font></td>                    \n");
      out.write("                </tr>\n");
      out.write("\n");
      out.write("                <tr>\n");
      out.write("                    <td>                    \n");
      out.write("                    ");

                     String cb1 = rs.getString("SubcompactCars");
                     String cb2 = rs.getString("CompactCars");
                     String cb3 = rs.getString("MidSizeCars");
                     String cb4 = rs.getString("FullSizeCars");
                     String cb5 = rs.getString("FamilyCars");
                     String cb6 = rs.getString("RaceCars");
                     String cb7 = rs.getString("SportsCars");
                     String cb8 = rs.getString("LuxuryCars");
                     if(!cb1.isEmpty())
                     {
                    
      out.write("\n");
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"Subcompact Cars\" value=\"Subcompact Cars\" checked/>\n");
      out.write("                        <font size=\"3\" >Subcompact Cars</font>\n");
      out.write("                    ");

                     }
                     else
                     {
                    
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"Subcompact Cars\" value=\"Subcompact Cars\"/>\n");
      out.write("                        <font size=\"3\" >Subcompact Cars</font>\n");
      out.write("                     ");

                     }
                     if(!cb2.isEmpty())
                     {
                    
      out.write("\n");
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"Compact Cars\" value=\"Compact Cars\" checked/>\n");
      out.write("                        <font size=\"3\" >Compact Cars</font>\n");
      out.write("                    ");

                     }
                     else
                     {
                    
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"Compact Cars\" value=\"Compact Cars\"/>\n");
      out.write("                        <font size=\"3\" >Compact Cars</font>\n");
      out.write("                     ");

                     }
                     if(!cb3.isEmpty())
                     {
                    
      out.write("\n");
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"MidSize Cars\" value=\"MidSize Cars\" checked/>\n");
      out.write("                        <font size=\"3\" >MidSize Cars</font>\n");
      out.write("                    ");

                     }
                     else
                     {
                    
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"MidSize Cars\" value=\"MidSize Cars\"/>\n");
      out.write("                        <font size=\"3\" >MidSize Cars</font>\n");
      out.write("                     ");

                     }
                     if(!cb4.isEmpty())
                     {
                    
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"FullSize Cars\" value=\"FullSize Cars\" checked/>\n");
      out.write("                        <font size=\"3\" >FullSize Cars</font>\n");
      out.write("                    ");

                     }
                     else
                     {
                    
      out.write("\n");
      out.write("                        <input type=\"checkbox\" name=\"FullSize Cars\" value=\"FullSize Cars\"/>\n");
      out.write("                        <font size=\"3\" >FullSize Cars</font>\n");
      out.write("                     ");

                     }
                    
      out.write("\n");
      out.write("                    </td>\n");
      out.write("                    <td><font size=\"3\" >Car</font></td>\n");
      out.write("                </tr>\n");
      out.write("                <tr><td>\n");
      out.write("                &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp\n");
      out.write("                <input type=\"submit\" name=\"Delete\" value=\"Delete\">\n");
      out.write("                &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp\n");
      out.write("                <input type=\"submit\" name=\"Update\" value=\"Update\">                    \n");
      out.write("                </td></tr>                    \n");
      out.write("            </table>\n");
      out.write("        ");

        } 
        else
        {
            out.println("<br><br><br><br><center><b><font size='5' color='red'>User does't exist</font></b></center><br><br><br><br/><br><br><br><br><br><br>");
        }
        
      out.write("\n");
      out.write("        <br>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
