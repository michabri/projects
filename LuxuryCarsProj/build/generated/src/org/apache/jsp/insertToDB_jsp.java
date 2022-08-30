package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import MyClasses.MyUtils;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.Connection;

public final class insertToDB_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("    Document   : insertToDB\n");
      out.write("    Created on : 16/08/2010, 00:06:59\n");
      out.write("    Author     : IP\n");
      out.write("--%>\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("\n");

            request.setCharacterEncoding("UTF-8");       //o קידוד לעברית
            // קבלת ערכי השדות מצד לקוח לצד שרת
           
            String first             = request.getParameter("first");
            String Email             = request.getParameter("Email");
            String pass1             = request.getParameter("pass1");
            String adress1           = request.getParameter("adress1");
            String adress2           = request.getParameter("adress2");
            String city              = request.getParameter("city");
            String SubcompactCars    = request.getParameter("SubcompactCars");
            String CompactCars       = request.getParameter("CompactCars");
            String MidSizeCars       = request.getParameter("MidSizeCars");
            String FullSizeCars      = request.getParameter("FullSizeCars");
            String FamilyCars        = request.getParameter("FamilyCars");
            String RaceCars          = request.getParameter("RaceCars");
            String SportsCars        = request.getParameter("SportsCars");
            String LuxuryCars        = request.getParameter("LuxuryCars");
            String update            = request.getParameter("update");
            String delete            = request.getParameter("delete");
            
            //O שלב שני - קישור למסד הנתונים
            String fullDbPath = MyUtils.getDBPath(application, "db\\siteDB.mdb");           
            Connection con    = MyUtils.getSiteDBconnectionWithJdbcOdbcDriver(fullDbPath);                
            //if(con == null)
            //{
              // out.println(MyUtils.getErrorText() + "</br>");
            //}  
            
            Statement stmt;
            stmt = con.createStatement();

            if(first == null)
                return;
            if(SubcompactCars==null)
                SubcompactCars= " ";
             if(CompactCars==null)
                CompactCars= " ";
             if(MidSizeCars==null)
                MidSizeCars= " ";
             if(FullSizeCars==null)
                FullSizeCars= " ";
              if(FamilyCars==null)
                FamilyCars= " ";
             if(RaceCars==null)
                RaceCars= " ";
             if(SportsCars==null)
                SportsCars= " ";
             if(LuxuryCars==null)
                LuxuryCars= " ";
            
            
            ////o יצירת שאילתת בחירה למסד לצורך בדיקת קיום המשתמש
            String sql = "SELECT * FROM users WHERE first='" + first + "'";
            ResultSet rs = stmt.executeQuery(sql);

            ////if user exists and update checked
            if(rs.next())
            {
                out.println("<body bgcolor='green'>"+"<center><h3>המשתמש כבר רשום</h3></center><br>");
                out.print("<center><br>"+"<a href='SignUpOrLogin.jsp'>חזרה לרישום</a></center>"); 
            }
            else
            {
              sql = "INSERT INTO users VALUES ('"
                + first + "','" +  Email +"','"+ pass1 +"','"+ adress1 +
                "','" + adress2 + "','"+ city + "','" + SubcompactCars + "','" 
                + CompactCars + "','" + MidSizeCars + "','" + FullSizeCars 
                + "','" + FamilyCars + "','" + RaceCars + "','" + SportsCars + "','" + LuxuryCars + "')";
              stmt.executeUpdate(sql);
              out.print("<body bgcolor='green'>");
              out.print("<center><h3>"+"המשתמש: " +first+ " "
                         +"<br/>נרשם בהצלחה"+"</h3></center><br>");
              out.print("<center><br>"+"<a href='index.jsp'>חזרה לרישום</a></center>");  
            }
            
                

            //O סגירת הקשר עם מסד הנתונים
            
            stmt.close();
            con.close();

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
