package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import MyClasses.MyUtils;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Connection;

public final class FindUserInDB_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n");
      out.write("   \"http://www.w3.org/TR/html4/loose.dtd\">\n");
      out.write("\n");

    request.setCharacterEncoding("UTF-8");       //o קידוד לעברית
    // קבלת ערכי השדות מצד לקוח לצד שרת           
    String name = request.getParameter("first");
    String password = request.getParameter("pass1");
    if (name == null || name == "")
    {
        out.println("<body bgcolor='green'>"+"<center><h3>User doesn't exist in the system</h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'>Back to Sign up or Login form</a></center>");
        return;
    }
    else
    {
       name = name.substring(0, 1).toUpperCase() + name.substring(1);
    }
    String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
    Connection con    = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                
    
    Statement stmt;
    stmt = con.createStatement();

    String sql = "SELECT * FROM users WHERE first='" + name + "'";
    ResultSet rs = stmt.executeQuery(sql);
    if(!rs.next())
    {
        out.println("<body bgcolor='green'>"+"<center><h3>User doesn't exist in the system</h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'>Back to Sign up or Login page</a></center>");     
    }
    else if (!(rs.getString("pass1").equals(password)))
    {
        out.println("<body bgcolor='green'>"+"<center><h3>User doesn't exist in the system</h3></center><br>");
        out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'>Back to Signup or Login form</a></center>");
        
    }
    else
    {
        out.println("<form action='UpdateDeleteUser.jsp'>");
        if(rs.getString("first").equals("Admin"))
        {
            out.println("<body bgcolor='black'><font face='algerian' color='white' size='10'>Luxury Edition</font><font face='algerian' color='white' size='4'><i>The World's Lucrative Marketplace</i></font><br><hr color='white'>");
            out.print("<center><h1><font color='white'>Administrator Menu</h1></font></center>");
            out.println("<center>First name: <input type='text' name='first' value='Admin'><br><input type='submit' value='Submit'><center></form>");
            out.println("<center><br>"+"<font color='white'><a href='SignUpOrLogin.jsp'>Back to Sign up or Login page</a></font></center>");
            out.print("");
        }
        else
        {
            out.print("<font size='10'>Confirm loading details for user<font></br>");
            out.print("<center><input type='text' name='first' readonly value='" + name +"'></br></br><input type='submit' value='Confirm'><center></form>");
        }
    }
        

      out.write('\n');
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
