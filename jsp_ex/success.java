package servlet;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Servlet implementation class Success
 */
@WebServlet("/success")
public class Success extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * @see HttpServlet#HttpServlet()
     */
    public Success() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		int mexam = Integer.parseInt(request.getParameter("mexam"));
		int fexam = Integer.parseInt(request.getParameter("fexam"));
		int report = Integer.parseInt(request.getParameter("report"));
		int attendance = Integer.parseInt(request.getParameter("attendance"));

		<HTML>
		<HEAD><TITLE>Fail</TITLE></HEAD>
		<BODY><H2>성적을 취득하였습니다!!</H2>
		<div>학번: " + request.getParameter("id") + "</div>
		<div>이름: " + request.getParameter("id") + "</div>
		<hr>
		<div>중간시험: " + String.valueOf(mexam) + "</div>
		<div>기말시험: " + String.valueOf(fexam) + "</div>
		<div>리포트: " + String.valueOf(report) + "</div>
		<div>출석: " + String.valueOf(attendance) + "</div>
		<hr>
		<div>총점은 " + String.valueOf(mexam + fexam + report + attendance) + "점 입니다.</div>

		</BODY></HTML>
	}
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
