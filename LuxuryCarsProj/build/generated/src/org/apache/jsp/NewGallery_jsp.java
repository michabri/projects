package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class NewGallery_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <title>Gallery</title>\n");
      out.write("        <script type=\"text/javascript\">\n");
      out.write("            var i=2;\n");
      out.write("            function next()\n");
      out.write("            {\n");
      out.write("                picture.src=\"pic/\"+i+\".jpg\";\n");
      out.write("                i++;\n");
      out.write("                if(i==10)\n");
      out.write("                    i=1;\n");
      out.write("\n");
      out.write("            }\n");
      out.write("            function back()\n");
      out.write("            {\n");
      out.write("                picture.src=\"pic/\"+i+\".jpg\";\n");
      out.write("                i--;\n");
      out.write("                if(i==0)\n");
      out.write("                    i=10;\n");
      out.write("\n");
      out.write("            }\n");
      out.write("        </script>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("    <body bgcolor=\"black\">\n");
      out.write("        <font face=\"algerian\" color=\"white\" size=\"10\">\n");
      out.write("        Luxury Edition\n");
      out.write("        </font>\n");
      out.write("        <font face=\"algerian\" color=\"white\" size=\"4\">\n");
      out.write("        <i>The World's Lucrative Marketplace</i> \n");
      out.write("        </font>\n");
      out.write("        <hr color=\"white\">\n");
      out.write("        <div class=\"relative\">\n");
      out.write("        <table border=\"4\" cellpadding=\"10\" style=\"margin-top:0px; margin-left:275px; border-color:white;\">\n");
      out.write("            <tr>\n");
      out.write("                <td>\n");
      out.write("                    <font face=\"garamond\" color=\"white\" size=\"5\">\n");
      out.write("                    For Sale\n");
      out.write("                    </font>\n");
      out.write("                </td>\n");
      out.write("                <td>\n");
      out.write("                    <font face=\"garamond\" color=\"white\" size=\"5\">\n");
      out.write("                    Specials\n");
      out.write("                    </font>\n");
      out.write("                </td>\n");
      out.write("                <td>\n");
      out.write("                    <font face=\"garamond\" color=\"white\" size=\"5\">\n");
      out.write("                    Stories\n");
      out.write("                    </font>\n");
      out.write("                </td>\n");
      out.write("                 <td>\n");
      out.write("                        <font face=\"garamond\" color=\"white\" size=\"5\">\n");
      out.write("                            <u><a href='SignUpOrLogin.jsp'><font color=\"#FFFFFF\">Sign up or Login </font></a></u>\n");
      out.write("                        </font>\n");
      out.write("                    </td>\n");
      out.write("                    <td>\n");
      out.write("                        <font face=\"garamond\" color=\"white\" size=\"5\">\n");
      out.write("                            <u><a href=\"NewGallery.jsp\"><font color=\"#FFFFFF\">Gallery</font></a></u>\n");
      out.write("                        </font>\n");
      out.write("                    </td>\n");
      out.write("                <td>\n");
      out.write("                    <form action=\"search.html\" method=\"GET\">\n");
      out.write("                    <input type=\"text\" name=\"q\" placeholder=\"Search LuxuryEdition\"/>\n");
      out.write("                    <input type=\"submit\" value=\"Search\"/>\n");
      out.write("                    </form>\n");
      out.write("                </td>\n");
      out.write("            </tr>\n");
      out.write("        </table>\n");
      out.write("        </div>\n");
      out.write("        <center>\n");
      out.write("            <font face=\"algerian\" color=\"white\" size=\"10\">\n");
      out.write("        Gallery\n");
      out.write("        </font>\n");
      out.write("            <br>\n");
      out.write("            <a href=\"MainMenu.jsp\"><font face=\"algerian\" color=\"white\" size=\"5\">Back to Main menu</font></a>\n");
      out.write("            <br>   <br> <br>\n");
      out.write("            <img id=\"picture\" src=\"pic/1.jpg\" alt=\"\" width=\"400px\" height=\"400px\"/> <br><br><br>\n");
      out.write("            <input type=\"submit\" value=\"next\" onclick=\"next()\"/> &nbsp&nbsp\n");
      out.write("            <input type=\"submit\" value=\"back\" onclick=\"back()\"/>\n");
      out.write("        </center>\n");
      out.write("         <br><br>\n");
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
