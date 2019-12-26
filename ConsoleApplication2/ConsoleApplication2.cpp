//////#include<iostream>
//////#include<fstream>
//////#include<string>
//////#include <filesystem>
//////#include <vector>
//////#include <windows.h>
//////#include <locale>
//////#include <codecvt>
//////#include <stdio.h>
//////#include <iostream>
//////#pragma warning(disable:4996)
//////namespace fs = std::filesystem;
//////
//////std::string string_To_UTF8(const std::string& str)
//////{
//////	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
//////	wchar_t* pwBuf = new wchar_t[nwLen + 1];    //一定要加1，不然会出现尾巴
//////	ZeroMemory(pwBuf, nwLen * 2 + 2);
//////	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
//////	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
//////	char* pBuf = new char[nLen + 1];
//////	ZeroMemory(pBuf, nLen + 1);
//////	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
//////
//////	std::string strRet(pBuf);
//////
//////	delete[]pwBuf;
//////	delete[]pBuf;
//////	pwBuf = NULL;
//////	pBuf = NULL;
//////
//////	return strRet;
//////}
//////
////////std::wstring String2WString111(const std::string& s)
////////{
////////	std::string strLocale = setlocale(LC_ALL, "");
////////	const char* chSrc = s.c_str();
////////	size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
////////	wchar_t* wchDest = new wchar_t[nDestSize];
////////	wmemset(wchDest, 0, nDestSize);
////////	mbstowcs(wchDest, chSrc, nDestSize);
////////	std::wstring wstrResult = wchDest;
////////	delete[]wchDest;
////////	setlocale(LC_ALL, strLocale.c_str());
////////	return wstrResult;
////////}
//////
//////std::string ToUTF8(const wchar_t* wideStr)
//////{
//////	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
//////	return conv.to_bytes(wideStr);
//////}
//////
//////int main()
//////{
//////	std::filesystem::path path_str("E:/render_temp_path/0_2016_167944/书房   _sddssd.vrscene");
//////	if (!std::filesystem::exists(path_str)) {
//////		return 0;
//////	}
//////
//////	//fs::path p = "C:cl.exe";
//////	//std::cout << "Current path is " << fs::current_path() << '\n'
//////	//	<< "Absolute path for " << p << " is " << fs::absolute(p) << '\n';
//////	//// 实际位置： "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\cl.exe"
//////
//////	//std::filesystem::path  p= "C:/Users/yinpinghua/Documents/3dsMax/../../Desktop/智网03543.jpg";
//////	////不存在
//////	//if (!std::filesystem::exists(p.string())){
//////	//	int i = 100;
//////	//}
//////
//////	////含有相对路径转换为绝对路径
//////	//std::string absolute_path = std::filesystem::absolute( p.string()).string();
//////
//////	//std::string str_path = std::filesystem::path(p).filename().string();
//////
//////	//std::string path_str = "E:/素材/散布动画模型/";
//////	//std::string path_str_str = "E:/素材/散布动画模型/散布.max";
//////
//////	//std::filesystem::path path1(path_str);
//////	//std::filesystem::path path2(path_str_str);
//////	//std::filesystem::absolute(path2, path1);
//////
//////	//std::filesystem::path p("E:\\素材\\散布动画模型\\iTrees-01_Bark-WillowOld-02.jpg");
//////	//std::filesystem::path base_path("E:\\素材\\散布动画模型\\");
//////	//std::filesystem::path base_path("E:\\");
//////	//std::string path_str = "E:/素材/散布动画模型/iTrees-01_Bark-WillowOld-02.jpg";
//////	//std::string base_path_str = "E:/素材/散布动画模型";
//////	//std::string path_str1 = std::filesystem::relative(path_str, base_path_str).string();
//////
//////	//std::string strrr = "//s/shar(可读写)/octopus/3dmax模型/现代简约客厅夜景/texture/2.jpg";
//////	//if (std::filesystem::is_regular_file(base_path_str))
//////	//{
//////	//	int i = 100;
//////	//}
//////
//////	//std::filesystem::path  p111= "C:/Users/yinpinghua/Documents/3dsMax/../../Desktop/智网03543.jpg";
//////
//////	//if (std::filesystem::is_regular_file(p111))
//////	//{
//////	//	int i = 100;
//////	//}
//////	//std::string pathss = std::filesystem::absolute(strrr).string();
//////	//std::string::size_type npos = pathss.find("\\");
//////	//std::error_code err_code;
//////	//std::filesystem::copy(pathss, "E:/", err_code);
//////	////err_code.value()
//////
//////
//////
//////	//std::string path = "E:/原型列子/0_2016_23340/Camera001.vrscene";
//////	//std::string test_str;
//////	//test_str.resize(100);
//////	//test_str.clear();
//////	//std::string path = "E:/原型列子/0_2018_18700/PhysCamera001.vrscene";
//////	//std::error_code ec;
//////	//bool r = std::filesystem::exists(path, ec);
//////	//if (!r || ec) {
//////	//	return 0;
//////	//}
//////
//////	//auto file_size = std::filesystem::file_size(path);
//////
//////	//std::string src_content;
//////	//const int fix_len = 3 * 1024 * 1024;
//////	//src_content.resize(fix_len);
//////	//std::ofstream out("test1.vrscene", std::ios::binary);
//////	////out.imbue(std::locale("chs"));
//////	//std::ifstream file(path, std::ios::binary);
//////	//if (!file.is_open()) {
//////	//	return 0;
//////	//}
//////
//////	//int i_data_size = 0;
//////	//bool is_find = false;
//////	//while (!is_find){
//////	//	file.read(&src_content[0], src_content.size());
//////	//	int64_t real_size = (int64_t)file.gcount();
//////	//	if (real_size < fix_len) {
//////	//		src_content.resize(real_size);
//////	//		is_find = true;
//////	//	}
//////
//////	//	std::string strstr = std::filesystem::u8path(src_content).string();
//////
//////	//	std::string sttttt = ToUTF8(String2WString111(strstr).c_str());
//////	//	out.write(&sttttt[0], sttttt.size());
//////	//	i_data_size +=strstr.size();
//////	//	std::cout << "i_data_size:" << i_data_size << std::endl;
//////	//}
//////
//////	//out.close();
//////	//file.close();
//////
//////	//return 0;
//////
//////}
//////
//////
////////#include <iostream>
////////#include<filesystem>
////////
////////int main()
////////{
////////	std::string strrr = "//s/shar(可读写)/octopus/3dmax模型/现代简约客厅夜景/texture/2.jpg";
////////	std::string file_name = std::filesystem::path(strrr).filename().string();
////////	std::string re_str = strrr.substr(0, strrr.find(file_name) - 1);
////////	std::string second_file_name = re_str.substr(re_str.rfind("/")+1, re_str.length());
////////
//////#include <iostream>
//////#include <filesystem>
//////#include <streambuf>
//////
//////int main()
//////{
//////	std::streambuf sbuf;
//////	char buffer[1000];
//////	sbuf.sgetn(buffer, 30000);
//////}
////
//////#include <fstream>
//////#include <iostream>
//////#include <filesystem>
//////namespace fs = std::filesystem;
//////
//////int main()
//////{
//////	std::filesystem::path p("E:/素材/2016模型路径贴图特殊字符");
//////	std::string str_path = p.u8string();
//////	try
//////	{
//////		for (auto& p : fs::recursive_directory_iterator("C:/"))
//////		{
//////			std::cout << p.path() << '\n';
//////		}
//////	}
//////	catch (const std::exception&e)
//////	{
//////		int i = 100l;
//////	}
//////
//////
//////	fs::remove_all("sandbox");
//////}
//
//#include <thread>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <mutex>
//#include <stack>
//#include <string>
//#include <exception>
//#include <memory> // For std::shared_ptr<>
//#include <queue>
//#include <condition_variable>
//#include <atomic>
//#include <future>
//#include <thread>
//#include <chrono>
//#include <filesystem>
//#include <memory>
//#include <windows.h>
//#include< Shlobj.h> //需要包含常量的定义
//
//using namespace std;
//
//int Add()
//{
//	cout << "Future add exe!" << endl;
//	return 1;
//}
//
//int Sum(int a, int b)
//{
//	return a + b;
//}
//
//struct MySum
//{
//	int Sum(int a, int b) { return a + b; }
//};
//
//void Display()
//{
//	std::future<void> v = std::async([]() {
//		while (1) {
//			std::cout << "eee" << std::endl;
//			std::this_thread::sleep_for(std::chrono::milliseconds(100));
//		}
//		});
//
//}
//
//void get_ip_port_from_url(const std::string url, std::string& ip, std::string& port,std::string& re)
//{
//	const char* pos = strstr(url.c_str(), "http://");
//	bool is_https = false;
//	if (pos == NULL){
//		pos = strstr(url.c_str(), "https://");
//		pos += strlen("https://");
//		is_https = true;
//	}
//
//	if (!is_https){
//		pos += strlen("http://");
//	}
//
//	if (strstr(pos, ":") == 0){
//		return;
//	}
//
//
//	char host[20] = {};
//	char Host[20] = {};
//	char c_port[20] = {};
//	char p_esource[100] = {};
//	char c_ip[20] = {};
//	//sscanf(pos, "%[^:]%[^/]", host, c_port);
//	//ip = host;
//	//port = strstr(c_port,":")+ strlen(":");
//
//	sscanf(pos, "%[^/]%s", Host, p_esource);
//	re = p_esource;
//	sscanf(Host, "%[0-9,.]:%[0-9]", c_ip, c_port);
//	ip = c_ip;
//	port = c_port;
//
//}
//
//
//
//int main()
//{
//	TCHAR szPath[MAX_PATH];
//	//SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_TEMPLATES, FALSE);
//	SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_MUSIC, FALSE);
//
//	std::string path_ = "E:/素材/2016模型路径贴图特殊字符/!##$ufjhh68464.max";
//
//	std::string file_name = std::filesystem::path(path_).filename().string();
//	std::string ssss1 = path_.substr(0, path_.rfind("/"));
//	std::string ssss = std::filesystem::relative(file_name, path_).string();
//	std::string sssssssssss = "Z:/work/2016-08-15鲁陇麓潞脢脨脰脴脟矛脗路鲁脟脢脨脰脨脨脛鲁脟脢脨脡猫录脝/GZ/ok/c10-碌脴脧脗鹿茫鲁隆.vrmap";
//	std::error_code ec;
//	try
//	{
//		std::string sss1 = std::filesystem::u8path(sssssssssss).string();
//	}
//	catch (const std::exception&e)
//	{
//		std::string strww = e.what();
//	}
//
//	char sztime1[16] = "";
//	char sztime2[16] = "";
//
//	//sscanf("192.168.2.3:8050", "%[^:]%s", sztime1,sztime2);
//	sscanf("192.168.2.3:8050", "%[0-9,.]:%[0-9]", sztime1, sztime2);
//	sscanf("2006:03:18-2006:04:18", "%[0-9,:] - %[0-9,:]", sztime1, sztime2);
//	std::shared_ptr<int>ptr;
//	if (ptr.get() == nullptr){
//		int i = 101;
//	}
//	std::string url = "http://192.168.96.3:54779/cloud_api/render_out/d3ecb6726de045e0b4d6ecb4afd58a57.7z";
//
//	std::wstring w_filename = std::filesystem::u8path(url).filename().wstring();
//	std::string ip;
//	std::string port;
//	std::string re;
//	get_ip_port_from_url(url, ip, port,re);
//
//	Display();
//	//int a = 100;
//	//int b = 200;
//	//std::future<int>future_fuc = std::async([a,b]()->int {
//	//	int i_value = (a + b);
//	//	return i_value;
//	//	});
//	//int i_value = future_fuc._Get_value();
//
//	//int i = 100
//
//	//异步函数
//	//std::future<void> v=std::async([]() {
//	//	while (1) {
//	//		std::cout << "eee" << std::endl;
//	//		std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	//	}
//	//	});
//
//		for (int i =0;i<100;i++)
//		{
//			std::cout << "ok" << std::endl;
//		}
//	//std::future<int> the_answer = std::async(std::launch::async/*std::launch::deferred*/, Add);
//
//	//// 通过延时来看期望的两个选项的差异(std::launch::async --- 异步线程执行,std::launch::deferred --- 延时执行)
//	////this_thread::sleep_for(chrono::seconds(10));
//	//std::cout << "The answer is " << the_answer.get() << std::endl;
//
//	//std::future<int> the_sum = std::async(Sum, 1, 2);
//	//std::cout << "The Sum is " << the_sum.get() << std::endl;
//
//	//MySum TheStructSum;
//	//std::future<int> StructSum = std::async(&MySum::Sum, TheStructSum, 3, 4);
//	//std::cout << "The Struct Sum is " << StructSum.get() << std::endl;
//
//	return 0;
//}
//
//
////#include <Windows.h>
////#include <iostream>
////#include <fstream>
////#include <filesystem>
////using namespace std;
////
////int main()
////{
////	std::string str_pat = "E:/temp/d3ecb6726de045e0b4d6ecb4afd58a57.7z";
////	std::string file_name = std::filesystem::absolute(str_pat).string();
////	std::string sss = std::filesystem::relative(file_name,str_pat).string();
////	TCHAR szFileName[MAX_PATH] = {};
////	OPENFILENAMEW openFileName = {};
////	openFileName.lStructSize = sizeof(OPENFILENAMEW);
////	openFileName.nMaxFile = MAX_PATH;//这个必须设置，不设置的话不会出现打开文件对话框
////	openFileName.lpstrFilter = L"文本文件（*.txt*）\0*.txt\0任何文件（*.*）\0*.*\0";
////	openFileName.lpstrFile = szFileName;
////	openFileName.nFilterIndex = 1;
////	openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
////
////	if (GetSaveFileName(&openFileName)){
////		MessageBox(nullptr, openFileName.lpstrFile, L"", MB_OK);
////	}
////
////	if (GetOpenFileName(&openFileName))// 如果保存则用GetSaveFileName()
////	{
////		MessageBox(nullptr, openFileName.lpstrFile, L"", MB_OK);
////		std::ifstream fin(openFileName.lpstrFile);
////		int a;
////		fin >> a;
////		fin.close();
////		wchar_t buffer[32] = {};
////		wsprintf(buffer, L"%d", a);
////		MessageBox(nullptr, buffer, L"", MB_OK);
////	}
////
////	return 0;
////}

//#include <windows.h>
//#include <tchar.h>
//#include <TlHelp32.h>
//#include <iostream>
//#include <string>
//
//std::string wstring_to_string(const std::wstring& wstr)
//{
//	std::string cur_locale = setlocale(LC_ALL, NULL); // curLocale = "C";
//	setlocale(LC_ALL, "chs");
//	const wchar_t* source = wstr.c_str();
//	size_t dsize = 2 * wstr.size() + 1;
//	char* dest_str = new char[dsize];
//	memset(dest_str, 0, dsize);
//	wcstombs(dest_str, source, dsize);
//	std::string result = dest_str;
//	delete[]dest_str;
//	setlocale(LC_ALL, cur_locale.c_str());
//	return result;
//}
//
//BOOL EnumProcessName();
//int main()
//{
//
//	if (EnumProcessName())
//	{
//		MessageBox(NULL, _T("检测到OD"), _T("结果"), MB_OK);
//	}
//	else
//	{
//		MessageBox(NULL, _T("没有检测到OD"), _T("结果"), MB_OK);
//	}
//	return 0;
//}
//
//BOOL EnumProcessName()
//{
//	TCHAR szOLLYDBG[] = _T("3dsmax.exe");  //要检测的OD进程名
//
//
//	PROCESSENTRY32 pe;
//	pe.dwSize = sizeof(PROCESSENTRY32);
//
//	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (INVALID_HANDLE_VALUE == hSnap)
//	{
//		MessageBox(NULL, _T("创建进程失败"), _T("错误"), MB_ICONERROR);
//		return FALSE;
//	}
//	if (Process32First(hSnap, &pe))
//	{
//		do
//		{
//			//if (lstrcmpi(szOLLYDBG, pe.szExeFile) == 0) //wstring对比函数
//			//{
//			//	return TRUE;
//			//}
//
//			std::wstring w_str(pe.szExeFile);
//		std::string str = wstring_to_string(w_str);
//		std::cout << str << std::endl;;
//		} while (Process32Next(hSnap, &pe));
//	}
//	CloseHandle(hSnap);
//	return FALSE; //其余都返回FALSE
//}

//#include <iostream>
//#include <algorithm>
//#include <filesystem>
//
//
//int main()
//{
//	std::string file_zip = "1111.zip";
//	std::filesystem::path(file_zip).filename().string();
//	std::string  str1 = "1111";
//	std::string str2 = "1111";
//
//	std::wstring w_str = L"11111";
//	//bool falg = lstrcmpi(w_str.c_str(), L"11111") == 0;
//	bool falg = strcmp(str1.c_str(),str2.c_str()) == 0;
//
//	//c++11
//	bool flag1 = std::wcscmp(w_str.c_str(), L"112111") == 0;
//
//}

//
//#include <iostream>
//#include <filesystem>
//#include"../sha1.hpp"
//#include "../nlohmann_json/json.hpp"
//
//using std::string;
////template <typename T>
////void show_list(T value) {   //当args包只有一项时，将调用这个版本
////	std::cout << value <<std::endl;
////}
//////也可以声明这样一个函数来结束递归：void show_list() {}，当args包为0时，将调用这个版本以结束递归
/////*****c++不定参数模板********/
////
////template <typename T, typename... Args>
////void show_list(T value, Args... args) {
////	std::cout << value << ", ";
////	show_list(args...);
////}
//
//template<typename T>
//int get(T count,T value)
//{
//	return count+value;
//}
//
//template <typename T, typename... Args>
//int get(T value, Args... args) {
//	int count =0;
//	count =get(count,args...);
//	return count;
//}
//
//int main()
//{
//	//int n = 14;
//	//int i =get(1, 2,3);
//	nlohmann::json js;
//
//	js["11"] = 22;
//	js["22"] = 33;
//	std::string strt = js.dump();
//
//	nlohmann::json js_str = nlohmann::json::parse(strt);
//
//	int a = js_str["11"];
//
//	sha1 sh;
//	sh.update("1111");
//	std::string sttt = sh.final();
//	std::cout << sttt << std::endl;
//
//}
//
//#include <iostream>
//#include <../iguana/iguana/json.hpp>
//#include <../iguana/iguana/xml.hpp>
//
//struct person
//{
//	std::string  name;
//	int          age;
//};
//REFLECTION(person, name, age)
//
//struct one_t
//{
//	int id;
//};
//REFLECTION(one_t, id);
//
//struct two
//{
//	std::string name;
//	one_t one;
//	int age;
//};
//REFLECTION(two, name, one, age);
//
//struct composit_t
//{
//	int a;
//	std::vector<std::string> b;
//	int c;
//	std::map<int, int> d;
//	std::unordered_map<int, int> e;
//	double f;
//	std::list<one_t> g;
//};
//REFLECTION(composit_t, a, b, c, d, e, f, g);
//
//struct madoka
//{
//	std::string	onegayi;
//	double		power;
//};
//
//REFLECTION(madoka, onegayi, power);
//
//void test_json()
//{
//	person p;
//	const char* json = "{ \"name\" : \"tom\", \"age\" : 20}";
//	auto r = iguana::json::from_json0(p, json);
//
//	iguana::string_stream ss;
//	iguana::json::to_json(ss, p);
//	std::cout << ss.str() << std::endl;
//
//	one_t one = { 2 };
//	composit_t composit = { 1,{ "tom", "jack" }, 3,{ { 2,3 } },{ { 5,6 } }, 5.3,{ one } };
//	iguana::string_stream sst;
//	iguana::json::to_json(sst, composit);
//	std::cout << sst.str() << std::endl;
//
//	//	const char* str_comp = R"({"a":1, "b":["tom", "jack"], "c":3, "d":{"2":3,"5":6},"e":{"3":4},"f":5.3,"g":[{"id":1},{"id":2}])";
//	const char* str_comp = R"({"b":["tom", "jack"], "a":1, "c":3, "e":{"3":4}, "d":{"2":3,"5":6},"f":5.3,"g":[{"id":1},{"id":2}])";
//	composit_t comp;
//	iguana::json::from_json0(comp, str_comp);
//	std::cout << comp.a << " " << comp.f << std::endl;
//}
//
//struct A
//{
//	void Display()
//	{
//		std::cout << "A struct" << std::endl;
//	}
//
//public:
//	int ivalue_;
//};
//
//constexpr int get_value(int a)
//{
//	return a;
//}
//
//template<typename T>
//constexpr bool  is_int64_v = std::is_same_v<T, std::int64_t> || std::is_same_v<T, std::uint64_t>;
//
//template<typename T>
//inline std::string to_str(T&& value) {
//	using U = std::remove_const_t<std::remove_reference_t<T>>;
//	if constexpr (std::is_integral_v<U> && !is_int64_v<U>) {
//		std::vector<char> temp(20, '\0');
//		itoa_fwd(value, temp.data());
//		return std::string(temp.data());
//	}
//	else if constexpr (is_int64_v<U>) {
//		std::vector<char> temp(65, '\0');
//		xtoa(value, temp.data(), 10, std::is_signed_v<U>);
//		return std::string(temp.data());
//	}
//	else if constexpr (std::is_floating_point_v<U>) {
//		std::vector<char> temp(20, '\0');
//		sprintf(temp.data(), "%f", value);
//		return std::string(temp.data());
//	}
//	else if constexpr (std::is_same_v<std::string, U> || std::is_same_v<const char*, U>) {
//		return value;
//	}
//	else {
//		std::cout << "this type has not supported yet" << std::endl;
//	}
//}
//
//void Mysplit(std::vector<std::string>& vec, const std::string& str, const std::string& demil)
//{
//	int pos = 0;
//	int start_pos = 0;
//	while (pos != std::string::npos){
//		pos = str.find(demil, start_pos);
//		if (pos==-1){
//			vec.push_back(str.substr(start_pos));
//			break;
//		}
//
//		if (pos == std::string::npos){
//		}else {
//			vec.push_back(str.substr(start_pos, pos - start_pos));
//		}
//
//		start_pos = pos + 1;
//	}
//}
//
//int main()
//{
//
//	 std::string str_split = "123,456,789:";
//	 std::vector<std::string>vec;
//	Mysplit(vec,str_split, ",:");
//	madoka m = { "Majyosine", 99999.999 };
//
//	iguana::string_stream ss;
//	iguana::xml::to_xml(ss, m);
//
//	auto xml_str = ss.str();
//	std::cout << xml_str << std::endl;
//
//	madoka m2;
//	iguana::xml::from_xml(m2, xml_str.data(), xml_str.length());
//
//	std::cout << m2.onegayi << " - " << m2.power << std::endl;
//
//	A a;
//	//别名
//	using Reflect_members = decltype(a);
//
//	Reflect_members D;
//	D.Display();
//
//	auto first = std::make_tuple(10, 'a',1.2f);
//
//	int i = std::get<0>(first);
//	char c = std::get<1>(first);
//	float f = std::get<2>(first);
//	test_json();
//}

//#include <iostream>
//#include <stdio.h>
//#include <vector>
////重载
////template<typename T,typename...Args>
////T* Instance(Args&&...args)
////{
////	return new T(std::forward<Args>(args)…);
////}
//
//struct A
//{
//	A(int a) {
//		std::cout << a << std::endl;
//	}
//
//	A(int a, int b) {
//		std::cout << a << std::endl;
//		std::cout << b << std::endl;
//	}
//};
//template<typename...Args>
//void OutPut(Args...args)
//{
//	int size = sizeof...(args);
//	auto p = std::make_tuple(std::forward<Args>(args)...);
//}
//
//template <class T>
//void test(T t)
//{
//	int count = std::tuple_size<T>::value;
//	int a[std::tuple_size<T>::value]; // can be used at compile time
//
//	std::cout << std::tuple_size<T>::value << '\n'; // or at run time
//}
//
//int main()
//{
//	int n = 10;
//	bool falg = true;
//	if (falg && (n>1)){
//		int i = 1;
//		int j = 0;
//	}
//	std::vector<int>vecs1{ 1,2,3,4 };
//	std::vector<int>vecs2{ 5,6,7,8 };
//	std::tuple < std::vector<int>, std::vector<int>>t(vecs1, vecs2);
//
//	std::tuple<int, std::string, float> t1(10, "Test", 3.14);
//	int i;
//	std::string str;
//	float f;
//	std::tie(i, str, f) = t1;//解出
//	std::tie(i, str, f) = t1;//解出
//	auto t2 = std::tuple_cat(t1, std::make_tuple("Foo", "bar")); //把两个tuple进行拼接
//
//	int count = std::tuple_size<decltype(t2)>::value; //算出总的tuple大小
//	test(std::make_tuple(1, 2, 3.14));
//
//	OutPut(1);
//	OutPut(1, 2);
//}

//#include <windows.h>
//#include <iostream>
//#include <filesystem>
//#include <string>
//#include <algorithm>
//#include <map>
//#include <time.h>
//#include "md5.h"
//#include <locale>
//#include <codecvt>
//#include<fstream>
//#include <memory>
//#pragma warning(disable:4996)
//#include <../octopus_third_party/md5/md5.hpp>
//
//#define SizeofArray(arr)sizeof(arr)/sizeof(arr[0])
//#define Sizeof(argum)sizeof(argum)/sizeof(argum)
//
//
//std::int64_t get_mill_time_stamp()
//{
//	std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//	auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
//	std::time_t timestamp = tmp.count();
//	return (int64_t)timestamp;
//}
//
//std::int64_t get_time_stamp()
//{
//	std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
//	auto tmp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
//	std::time_t timestamp = tmp.count();
//	return (int64_t)timestamp;
//}
//
//std::tm* gettm(int64_t timestamp)
//{
//	int64_t milli = timestamp + (int64_t)8 * 60 * 60 * 1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//	auto mTime = std::chrono::milliseconds(milli);
//	auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
//	auto tt = std::chrono::system_clock::to_time_t(tp);
//	std::tm* now = std::gmtime(&tt);
//	printf("%4d年%02d月%02d日 %02d:%02d:%02d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
//	return now;
//}
//
//std::wstring timewstr_from_tm(int64_t timestamp, std::wstring format)
//{
//	int64_t milli = timestamp + (int64_t)8 * 60 * 60 * 1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//	auto mTime = std::chrono::milliseconds(milli);
//	auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
//	auto tt = std::chrono::system_clock::to_time_t(tp);
//	std::tm* now = std::gmtime(&tt);
//	std::wstring str;
//	str.resize(64);
//	std::wcsftime(&str[0], str.size(), format.c_str(), now);
//	return str;
//}
//
//std::string milltimestr_from_tm(int64_t timestamp, std::string format)
//{
//	int64_t milli = timestamp + (int64_t)8 * 60 * 60 * 1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//	auto mTime = std::chrono::milliseconds(milli);
//	auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
//	auto tt = std::chrono::system_clock::to_time_t(tp);
//	std::tm* now = std::gmtime(&tt);
//	std::string str;
//	str.resize(64);
//	std::strftime(&str[0], str.size(), format.c_str(), now);
//	return str;
//}
//
//std::string timestr_from_tm(int64_t timestamp, std::string format)
//{
//	int64_t milli = timestamp + (int64_t)8 * 60 * 60;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//	auto mTime = std::chrono::seconds(milli);
//	auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>(mTime);
//	auto tt = std::chrono::system_clock::to_time_t(tp);
//	std::tm* now = std::gmtime(&tt);
//	std::string str;
//	str.resize(64);
//	std::strftime(&str[0], str.size(), format.c_str(), now);
//	return str;
//}
//
//
//std::wstring string_to_wstring(const std::string& s)
//{
//	std::string strLocale = setlocale(LC_ALL, "");
//	const char* chSrc = s.c_str();
//	size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
//	wchar_t* wchDest = new wchar_t[nDestSize];
//	wmemset(wchDest, 0, nDestSize);
//	mbstowcs(wchDest, chSrc, nDestSize);
//	std::wstring wstrResult = wchDest;
//	delete[]wchDest;
//	setlocale(LC_ALL, strLocale.c_str());
//	return wstrResult;
//}
//
//std::int64_t standard_to_stamp(char* str_time) {
//	struct tm stm;
//	int iY, iM, iD, iH, iMin, iS;
//	memset(&stm, 0, sizeof(stm));
//	iY = atoi(str_time);
//	iM = atoi(str_time + 5);
//	iD = atoi(str_time + 8);
//	iH = atoi(str_time + 11);
//	iMin = atoi(str_time + 14);
//	iS = atoi(str_time + 17);
//	stm.tm_year = iY - 1900;
//	stm.tm_mon = iM - 1;
//	stm.tm_mday = iD;
//	stm.tm_hour = iH;
//	stm.tm_min = iMin;
//	stm.tm_sec = iS;
//
//	return (long)mktime(&stm);
//}
//
////u8string to wstring
//std::wstring utf8_to_wstring(const std::string& str)
//{
//	std::wstring_convert< std::codecvt_utf8_utf16<wchar_t> > strCnv;
//	return strCnv.from_bytes(str);
//}
//
////wstring to string
////wstring to u8string
//std::string utf8_to_wstring(const std::wstring& str)
//{
//	std::wstring_convert< std::codecvt_utf8_utf16<wchar_t> > strCnv;
//	return strCnv.to_bytes(str);
//
//}
//
////wstring to string
//std::string wstring_to_string(const std::wstring& str)
//{
//	std::wstring_convert< std::codecvt_utf8_utf16<wchar_t> > strCnv;
//	return strCnv.to_bytes(str);
//}
//
//// utf-8 to utf16
//std::u16string utf8_to_u16string(const std::string& str)
//{
//	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> strCnv;
//	return strCnv.from_bytes(str);
//}
//
////utf16 to utf-8
//std::string u16string_to_utf8(const std::u16string& str)
//{
//	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> strCnv;
//	return strCnv.to_bytes(str);
//}
//
////utf-8 to utf-32
//std::u32string utf8_utf32(std::string str)
//{
//	std::wstring_convert< std::codecvt_utf8<char32_t>, char32_t >strCnv;
//	return strCnv.from_bytes(str);
//}
//
////utf-32 to utf-8
//std::string u32string_to_utf8(std::u32string str)
//{
//	std::wstring_convert< std::codecvt_utf8<char32_t>, char32_t >strCnv;
//	return strCnv.to_bytes(str);
//}
//
//int main()
//{
//	//std::string str = "1223";
//	//std::string md5_str =cmd5::md5(str);
//	//std::string mddd = cmd5::md5sum6(str);
//
//	//std::string path1111 = "E:/我是hi好人 wwwwwwww jjjjjjj www/aaaa/";
//	//std::string u8_pah = std::filesystem::path(path1111).u8string();
//	//std::string path = std::filesystem::u8path(u8_pah).string();
//
//	//if (!std::filesystem::exists(path)){
//	//	std::error_code ec;
//	//	std::filesystem::create_directories(path, ec);
//	//	if (ec.value()==0){
//	//		int i = 100;
//	//	}
//	//}
//	//
//
//	std::string path_file = "E:/素材/球体动画2018.max";
//	std::string sss1 = std::filesystem::path(path_file).extension().string();
//
//	if (sss1.compare("max") ==0){
//		int i = 100;
//	}
//	std::map<int, int>g_max_version;
//	int version = 2012;
//	for (int num = 14; num < 23; num++ ) {
//		g_max_version.emplace(num, version);
//		version++;
//	}
//
//	std::string u8string = wstring_to_string(L"我是好人");
//	std::u16string u16 = utf8_to_u16string(u8string);
//
//	std::wstring w_str = string_to_wstring("我是好人");
//	std::string sss = u16string_to_utf8(u16);
//	std::string ssss = std::filesystem::path("我是好人").u8string();
//
//	std::string str4 = "words and 2";
//
//	try
//	{
//		std::exception code;
//	}
//	catch (std::exception & e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//
//	std::string str;
//	if (str.empty()) {
//		int i = 100;
//	}
//	std::string base = "The quick brown fox jumps over a lazy dog.";
//
//	// used in the same order as described above:
//
//	str.assign(base); //就把后者值给前者值
//
//	std::chrono::system_clock::time_point latest_tm_ = std::chrono::system_clock::now();
//	time_t rawtime;
//	struct tm* timeinfo;
//
//	char s[100];
//	rawtime = time(NULL);
//	timeinfo = localtime(&rawtime);
//	time_t tick = mktime(timeinfo);
//	std::string sttttt = asctime(timeinfo);
//
//	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", timeinfo);
//	std::int64_t ss = standard_to_stamp(s);
//
//	//std::vector<int> tmp(10, 1);
//	//tmp.push_back(100);
//	//int size = tmp.size();
//	//tmp.resize(10);
//	//std::cout << tmp[0] << std::endl;
//
//	std::time_t mill_time_stamp = get_mill_time_stamp();
//	std::time_t time_stamp = get_time_stamp();
//	std::string w_format_str = timestr_from_tm(time_stamp, "%Y-%m-%d %H:%M:%S");
//
//	int arr[] = { 1,2,3,4,5 };
//	std::vector<int>vec(arr, arr + SizeofArray(arr));
//
//	std::map<int, int>m{ {1,2},{2,3},{3,4} };
//	int index = 2;
//	auto fun = [&index](std::pair<int, int>p)->bool {return p.first == index; };
//	auto iter = find_if(m.begin(), m.end(), fun);
//	int u = 100;
//}

//#include <iostream>
//using namespace std;
//
//#include <boost/asio/ip/tcp.hpp >
//#include <boost/asio.hpp>
//#include <filesystem>
//
//std::string query_ip(std::string dns)
//{
//	boost::asio::ip::tcp::resolver::query oQuery(dns, "http");
//	boost::asio::io_service oIoSrv;//IO服务对象来执行一个IO上的操作
//	boost::asio::ip::tcp::resolver oResolver(oIoSrv);//来表示一个域名和服务类型的解释操作
//
//	//进行域名或者服务解释，以便生成SOCKET内部使用的数据格式
//	boost::asio::ip::tcp::resolver::iterator itBegin = oResolver.resolve(oQuery), itEnd;
//	if (itBegin == itEnd)
//	{
//		return "";
//	}
//
//	//解释成功之后， 显示解释后的IP地址和端口
//	boost::asio::ip::tcp::endpoint oEndPt = itBegin->endpoint();
//	return  oEndPt.address().to_string();
//}
//
//std::string str = "http://service.zwrender.com:54779/cloud_api/render_out/010019121087nc6n/010019121087nc6n.zip";
//
//std::tuple<std::string, std::string, std::string> get_res() {
//	auto pos = str.find("//");
//	auto str1 = str.substr(pos + 2);
//
//	auto pos2 = str1.find("/");
//	auto str2 = str1.substr(pos2);
//
//	auto str3 = str1.substr(0, pos2);
//	auto pos4 = str3.find(":");
//
//	auto str4 = str3.substr(pos4+1);
//	auto str5 = str3.substr(0, pos4);
//
//	return { str2, str4, str5 };
//}
//
//int main()
//{
//	get_res();
//	std::string  ip = query_ip("192.168.96.9");
//
//	return 0;
//}

//#include<windows.h>
//#include <stdio.h>
//#include <tchar.h>
//#pragma warning(disable:4996)
//
//
//
//int main(void)
//{
//	wchar_t buffer[MAX_PATH];
//	DWORD code = GetEnvironmentVariable(L"VRAY_MDL_PATH_3DSMAX2014", buffer, MAX_PATH);
//
//	TCHAR szSourcePath2[MAX_PATH] = _T("%ProgramFiles(x86)%\\Tencent\\QQBrowser");
//	TCHAR szSourcePath2[MAX_PATH] = _T("%INTEL_DEV_REDIST%compiler\\lib\\intel64_win_mic");
//	TCHAR szSourcePath2[MAX_PATH] = _T("VRAY_MDL_PATH_3DSMAX2014");
//	TCHAR szSourcePath2[MAX_PATH] = _T("%USERPROFILE%");
//	TCHAR szSourcePath2[MAX_PATH] = _T("%VRAY_MDL_PATH_3DSMAX2016%");
//	TCHAR szDestPath2[2048] = { 0 };
//	ExpandEnvironmentStrings(szSourcePath2, szDestPath2, MAX_PATH - 1);
//
//
//	char* pathvar;
//
//	pathvar = getenv("PATH");
//
//	printf("pathvar=%s", pathvar);
//	return 0;
//
//}

//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//#include<strsafe.h>
//#include <boost/filesystem.hpp>
//#include <iostream>
//#pragma warning(disable:4996)
//
//using  namespace std;
//int main()
//{
//
//	char* pathvar;
//	pathvar = getenv("Path");
//	printf("pathvar=%s", pathvar);
//
//	wchar_t filename[100] = {};
//	SearchPath(L".\\", _T("Chaos Group"), NULL, 100, filename, NULL);
//
//	TCHAR szOutBuf[MAX_PATH] = { 0 };
//	GetEnvironmentVariable(_T("VRAY"), szOutBuf, MAX_PATH - 1);
//
//	TCHAR szOutBuf2[MAX_PATH] = { 0 };
//	GetEnvironmentVariable(_T("ProgramFiles(x86)"), szOutBuf2, MAX_PATH - 1);
//
//
//	LPTSTR lpszVariable;
//	LPTCH lpvEnv;//LPTCH就是WCHAR *数据类型，指向宽字符的指针变量
//	size_t iTarget;
//	//调用GetEnvironmentStrings函数获取完整的环境变量内存块，并让lpvEnv指向这个内存块
//	lpvEnv = GetEnvironmentStrings();
//	//如果获取的环境块为空，则该函数调用失败，并获取错误代码
//	if (lpvEnv == NULL)
//	{
//		_tprintf(TEXT("GetEnvironmentStrings failed(%d)\n"), GetLastError());
//		return 0;
//	}
//	//lpvEnv指向的环境变量字符串是以NULL分隔的，即'\0'分隔，可以回去看前面我展示的环境字符串的大概格式。而字符串最后是以NULL结尾的
//	lpszVariable = (LPTSTR)lpvEnv;
//	while (*lpszVariable)
//	{
//		_tprintf(TEXT("%s\n"), lpszVariable);
//		StringCchLength(lpszVariable, 1000, &iTarget);//PATH的值太长，我设1000为最大允许字符数
//		lpszVariable += iTarget + 1;//移动指针，访问下一环境变量的值
//	}
//	//如果GetEnvironmentStrings函数返回的内存块不用了，记得要释放掉
//	FreeEnvironmentStrings(lpvEnv);
//	system("pause");
//	return 1;
//}
//

//#include <time.h>
//#include <windows.h>
//#include <iostream>
//#include <stdio.h>
//#include <tchar.h>
//#include <fstream>
//#include <queue>
//#include <tchar.h>
//#include <vector>
//#define MAX_KEY_LENGTH 255
//#define MAX_VALUE_NAME 16383
//DWORD dwType = REG_BINARY | REG_DWORD | REG_EXPAND_SZ | REG_MULTI_SZ | REG_NONE | REG_SZ;
//std::queue<std::wstring> keystack;
//
////#define COMMAND_OUTPUT
//
//void query(HKEY rootKey, const wchar_t* path, std::vector<std::wstring>&vecs)
//{
//	HKEY hKey;
//	if (RegOpenKeyEx(rootKey, path, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
//	{
//		RegCloseKey(hKey);
//		return;
//	}
//
//	TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
//	DWORD    cbName;                   // size of name string
//	TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
//	DWORD    cchClassName = MAX_PATH;  // size of class string
//	DWORD    cSubKeys = 0;               // number of subkeys
//	DWORD    cbMaxSubKey;              // longest subkey size
//	DWORD    cchMaxClass;              // longest class string
//	DWORD    cValues;              // number of values for key
//	DWORD    cchMaxValue;          // longest value name
//	DWORD    cbMaxValueData;       // longest value data
//	DWORD    cbSecurityDescriptor; // size of security descriptor
//	FILETIME ftLastWriteTime;      // last write time
//
//	DWORD i, retCode;
//
//	TCHAR  achValue[MAX_VALUE_NAME];
//	DWORD cchValue = MAX_VALUE_NAME;
//
//	// Get the class name and the value count.
//	retCode = RegQueryInfoKey(
//		hKey,                    // key handle
//		achClass,                // buffer for class name
//		&cchClassName,           // size of class string
//		NULL,                    // reserved
//		&cSubKeys,               // number of subkeys
//		&cbMaxSubKey,            // longest subkey size
//		&cchMaxClass,            // longest class string
//		&cValues,                // number of values for this key
//		&cchMaxValue,            // longest value name
//		&cbMaxValueData,         // longest value data
//		&cbSecurityDescriptor,   // security descriptor
//		&ftLastWriteTime);       // last write time
//
//	// Enumerate the subkeys, until RegEnumKeyEx fails.
//	if (cSubKeys>0)
//	{
//		for (i = 0; i < cSubKeys; i++)
//		{
//			cbName = MAX_KEY_LENGTH;
//			retCode = RegEnumKeyEx(hKey, i,
//				achKey,
//				&cbName,
//				NULL,
//				NULL,
//				NULL,
//				&ftLastWriteTime);
//			if (retCode == ERROR_SUCCESS)
//			{
//				//use achKey to build new path and input it into stack.
//				std::wstring newPath = L"";
//				newPath.append(path);
//				newPath.append(L"\\");
//				newPath.append(achKey);
//				keystack.push(newPath);
//			}
//		}
//	}
//
//	// Enumerate the key values.
//	if (cValues>0)
//	{
//		for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++)
//		{
//			cchValue = MAX_VALUE_NAME;
//			achValue[0] = '\0';
//			unsigned char vari[70];
//			retCode = RegEnumValue(hKey, i,
//				achValue,
//				&cchValue,
//				NULL,
//				NULL,
//				NULL,
//				NULL);
//			if (retCode == ERROR_SUCCESS)
//			{
//				TCHAR szBuffer[255] = { 0 };
//				DWORD dwNameLen = 255;
//				DWORD rQ = RegQueryValueEx(hKey, achValue, 0, &dwType, (LPBYTE)szBuffer, &dwNameLen);
//				if (rQ == ERROR_SUCCESS)
//				{
//					std::wstring info = std::wstring(achValue)+std::wstring(L"=")+ std::wstring(szBuffer);
//					vecs.push_back(info);
//					//_tprintf(TEXT("(%d) %s %s\n"), i + 1, achValue, szBuffer);
//				}
//
//			}
//		}
//	}
//	//release.
//	RegCloseKey(hKey);
//}
//
//void regQuery(HKEY beginKey, std::wstring path)
//{
//	//Begin to get HKEY of path.
//	std::vector<std::wstring>wstrs;
//	query(beginKey, path.c_str(),wstrs);
//	while (!keystack.empty())
//	{
//		std::wstring newPath = keystack.front();
//		keystack.pop();
//		query(beginKey, newPath.c_str(), wstrs);
//	}
//
//	//Release.
//	RegCloseKey(beginKey);
//}
//
//void char_to_wchar(const char* ch, std::wstring& w_str)
//{
//	wchar_t* wchar;
//	int len = MultiByteToWideChar(CP_ACP, 0, ch, strlen(ch), NULL, 0);
//	wchar = new wchar_t[len + 1];
//	MultiByteToWideChar(CP_ACP, 0, ch, strlen(ch), wchar, len);
//	wchar[len] = '\0';
//	w_str = wchar;
//	delete[]wchar;
//}
//
//int main()
//{
//	std::wstring wstr;
//	char_to_wchar("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment", wstr);
//	regQuery(HKEY_LOCAL_MACHINE, wstr);
//	return 0;
//}
//

//#include <vector>
//#include <list>
//#include <string>
//struct MyStruct
//{
//	int ver = 0;
//};
//
////bool compare(const MyStruct& x, const MyStruct& y) {
////	return x.ver <y.ver;
////}
//int main()
//{
//	//char ss1[] = { '1','2' };
//	//std::string ssss(ss1, 2);
//	//std::string ss = "111222";
//	//if (ss._Starts_with("111")) {
//	//	int i = 100;
//	//}
//
//	std::wstring w_str = L"mblen";
//	int size = wcslen(w_str.c_str());
//
//	std::wstring is = std::to_wstring(100);
//	std::list<MyStruct>vecs;
//	for (int i = 0; i < 5; i++) {
//		MyStruct s;
//		s.ver = i;
//		vecs.push_back(s);
//	}
//
//	vecs.sort([](const MyStruct& x, const MyStruct& y)->bool {return x.ver > y.ver; });
//	//sort(vecs.begin(), vecs.end(), [](const MyStruct& x, const MyStruct& y)->bool{return x.ver >y.ver;});
//	int i = 10;
//}

//#include <cpp_redis/cpp_redis>
//
//#include <iostream>
//
//#ifdef _WIN32
//#include <Winsock2.h>
//#pragma comment(lib,"tacopie.lib")
//#pragma comment(lib,"cpp_redis.lib")
//#endif /* _WIN32 */
//
//int main(void) {
//#ifdef _WIN32
//	//! Windows netword DLL init
//	WORD version = MAKEWORD(2, 2);
//	WSADATA data;
//
//	if (WSAStartup(version, &data) != 0) {
//		std::cerr << "WSAStartup() failure" << std::endl;
//		return -1;
//	}
//#endif /* _WIN32 */
//
//	cpp_redis::active_logger = std::unique_ptr<cpp_redis::logger>(new cpp_redis::logger);
//	cpp_redis::client client;
//	//client.add_sentinel("192.168.96.9", 6379);
//
//	client.connect("192.168.96.9", 6379, [](const std::string& host, std::size_t port, cpp_redis::client::connect_state status) {
//		if (status == cpp_redis::client::connect_state::dropped) {
//			std::cout << "client disconnected from " << host << ":" << port << std::endl;
//		}
//		});
//
//	//client.auth("123456", [](cpp_redis::reply& reply) {
//	//	std::cout << "select: " << reply << std::endl;
//	//	});
//
//	auto f = client.auth("123456");
//	client.select(0);
//
//	//client.setnx("11", "22", [](cpp_redis::reply& reply) {
//	//	std::cout << "setnx " << reply << std::endl;
//	//	});
//
//
//	client.setbit_("111",20,"1", [](cpp_redis::reply& reply) {
//		std::cout << "setbit_ " << reply << std::endl;
//		});
//
//	client.getbit("111", 20, [](cpp_redis::reply& reply) {
//		std::cout << "getbit " << reply << std::endl;
//		});
//
//	//client.setex("11:22:2019-12-17", 120, "33", [](cpp_redis::reply& reply) {
//	//	std::cout << "setnx " << reply << std::endl;
//	//	});
//
//	//client.get("11:22:2019-12-17", [](cpp_redis::reply& reply) {
//	//	if (!reply.is_null()) {
//	//		std::string ss = reply.as_string(); //健值对
//	//		std::cout << "setnx " << reply << std::endl;
//	//	}
//	//	});
//
//	//client.send({ "SET", "hello", "42" }, [](cpp_redis::reply& reply) {
//	//	std::cout << "set hello 42: " << reply << std::endl;
//	//	});
//
//	//client.del({ "hello" }, [](cpp_redis::reply& reply) {
//	//	std::cout << "del hello 42: " << reply << std::endl;
//	//	});
//
//	//client.sync_commit();
//	client.commit();
//	f.wait();
//	//client.select(0, [](cpp_redis::reply& reply) {
//	//	if (reply.ok()) {
//	//		std::cout << "ok" << std::endl;
//	//	}
//
//	//	std::cout << "select: " << reply << std::endl;
//	//	});
//
//	//client.sync_commit();
//	//client.send({ "SET", "hello", "42" });
//	//same as
//	//client.send({ "SET", "hello", "42" }, [](cpp_redis::reply& reply) {
//	//	std::cout << "set hello 42: " << reply << std::endl;
//	//	});
//
//	//client.commit();
//	//client.set("hello", "42", [](cpp_redis::reply& reply) {
//	//	std::cout << "set hello 42: " << reply << std::endl;
//	//	// if (reply.is_string())
//	//	//   do_something_with_string(reply.as_string())
//	//	});
//
//	// same as client.send({ "DECRBY", "hello", 12 }, ...)
//	//client.decrby("hello", 12, [](cpp_redis::reply& reply) {
//	//	std::cout << "decrby hello 12: " << reply << std::endl;
//	//	// if (reply.is_integer())
//	//	//   do_something_with_integer(reply.as_integer())
//	//	});
//
//	// same as client.send({ "GET", "hello" }, ...)
//	//client.get("hello", [](cpp_redis::reply& reply) {
//	//	std::cout << "get hello: " << reply << std::endl;
//	//	// if (reply.is_string())
//	//	//   do_something_with_string(reply.as_string())
//	//	});
//
//	// commands are pipelined and only sent when client.commit() is called
//	// client.commit();
//
//	// synchronous commit, no timeout
//	//client.sync_commit();
//
//	// synchronous commit, timeout
//	// client.sync_commit(std::chrono::milliseconds(100));
//
//#ifdef _WIN32
//	WSACleanup();
//#endif /* _WIN32 */
//
//	return 0;
//}
//
//#include <iostream>
//
//#include <boost/asio.hpp>
//
//void Display()
//{
//	std::cout << "ssss" << std::endl;
//}
//int main()
//{
//	boost::asio::io_service io;
//
//	boost::asio::steady_timer timer_(io);
//
//	timer_.expires_from_now(std::chrono::seconds(1));
//
//	timer_.async_wait([](boost::system::error_code const& ec) {
//		if (ec) {
//			return;
//		}
//
//		Display();
//		});
//
//	while (1) {
//		std::this_thread::sleep_for(std::chrono::seconds(2));
//		continue;
//	}
//}

//#include <iostream>
//#include <boost/asio.hpp>
//boost::asio::io_service io;
//boost::asio::deadline_timer t1(io, boost::posix_time::seconds(5));
////boost::asio::steady_timer t1(io);
//
//int count = 0;
//
//void start_time();
//void start_time_handle(const boost::system::error_code& ec)
//{
//	if (ec) {
//		return;
//	}
//
//	start_time();
//
//	std::cout << "start_time_handle" << std::endl;
//}
//
//void start_time()
//{
//	t1.expires_from_now(boost::posix_time::seconds(5));
//	t1.async_wait(std::bind(start_time_handle, std::placeholders::_1));
//}
//
//int main()
//{
//	start_time();
//	//t1.async_wait(std::bind(Display, std::placeholders::_1, &t1));
//
//	//t1.async_wait([](const boost::system::error_code& ec) {
//	//	if (ec) {
//	//		return;
//	//	}
//
//	//	std::cout << "ssss" << std::endl;
//	//	});
//
//	io.run();
//}
//
//#include <iostream>
//#include <boost/asio.hpp>
//#include <memory>
//typedef boost::asio::ip::tcp TCP;
//boost::asio::io_service io;
//boost::asio::ip::tcp::acceptor ac(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8888));
//void accept()
//{
//	std::shared_ptr<TCP::socket> socket_ = std::make_shared<TCP::socket>(io);
//	ac.async_accept(*socket_, [socket_](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		std::cout << socket_->remote_endpoint().address().to_string() << std::endl;
//		远程端口
//		std::cout << socket_->remote_endpoint().port() << std::endl;
//		accept();
//		});
//}
//
//int main()
//{
//	accept();
//	io.run();
//}
//
//#include <iostream>
//
//int main()
//{
//	std::string msg;
//	char write_buffer_[123] = { 0 };
//
//	memcpy(write_buffer_, "123", 3);
//	std::copy(msg.begin(), msg.end(), write_buffer_);
//	int i = 10;
//}
//
//#include <iostream>
//#include <chrono>
//
//enum class OS { Linux, Mac, Windows };
//const OS the_os = OS::Linux;
//
//void do_something() {
//	//do something general
//
//	if constexpr (the_os == OS::Linux) {
//		int i = 100;
//		//do something Linuxy
//	}
//	else if constexpr (the_os == OS::Mac) {
//		//do something Appley
//	}
//	else if constexpr (the_os == OS::Windows) {
//		//do something Windowsy
//	}
//
//	//do something general
//}
//
//int main()
//{
//	//std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
//	//auto tmp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch()).count();
//
//	//auto tm11 = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//
//	//auto tm12 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//
//	do_something();
//
//}

//#include <iostream>
//#include <codecvt>
//#include <locale>
//
//#pragma warning(disable:4996)
//int main()
//{
//	std::string str = "123";
//	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
//	std::wstring wstr = conv.from_bytes(str.c_str());
//
//	//size_t nDestSize = mbstowcs(NULL, str.c_str(), 0) + 1;
//	////size_t nDestSize = strlen(str.c_str()) + 1;
//	//wchar_t* wchDest = new wchar_t[nDestSize];
//	//wmemset(wchDest, 0, nDestSize);
//	//mbstowcs(wchDest, str.c_str(), nDestSize);
//	//std::wstring wstrResult = wchDest;
//	//delete[]wchDest;
//	//wchDest = nullptr;
//}

//#include <iostream>
//#include <boost/asio.hpp>
//#include <memory>
//typedef boost::asio::ip::tcp TCP;
//boost::asio::io_service io;
//boost::asio::ip::tcp::acceptor ac(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8888));
//void accept()
//{
//	std::shared_ptr<TCP::socket> socket_ = std::make_shared<TCP::socket>(io);
//	ac.async_accept(*socket_, [socket_](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		std::cout << socket_->remote_endpoint().address().to_string() << std::endl;
//		//远程端口
//		std::cout << socket_->remote_endpoint().port() << std::endl;
//		accept();
//		});
//}
//
//int main()
//{
//	accept();
//	io.run();
//}

//#include "server_http.hpp"
//#include "handler.hpp"
//
//using namespace ShiyanlouWeb;
//
//int main() {
//	// HTTP 服务运行在 12345 端口，并启用四个线程
//	Server<HTTP> server(12345, 4);
//	start_server<Server<HTTP>>(server);
//	return 0;
//}


//#include <iostream>
//#include <regex>
//
//int main()
//{
//	std::regex e("^([^ ]*)3DSMAX(\\d{4})_MAIN([^ ]*)");
//	//std::regex e("([^ ]*)3DSMAX(\\d{4})_MAIN");
//
//	std::smatch sub_match;
//
//	//从第一行中解析请求方法、路径和 HTTP 版本
//	std::string line = "VRAY30_RT_FOR_3DSMAX2016_MAIN";
//	if (std::regex_match(line, sub_match, e)) {
//		int i = 100;
//	}
//
//	std::wregex re(L"^([^ ]*)3DSMAX(\\d{4})_MAIN([^ ]*)");
//	std::wsmatch w_sub_match;
//
//	std::wstring w_line = L"VRAY30_RT_FOR_3DSMAX2016_MAIN";
//	if (std::regex_match(w_line, w_sub_match, re)) {
//		int i = 100;
//	}
//
//	int i = 100;
//
//}

//#include <iostream>
//#include <boost/asio.hpp>
//#include <chrono>
//boost::asio::io_service io;
////此地方一定要给时间，否则定时器不起作用
//boost::asio::deadline_timer timer_(io, boost::posix_time::seconds(0));
//boost::asio::steady_timer timer1_(io,std::chrono::seconds(0));
//
//boost::asio::deadline_timer timer2_(io);
//boost::asio::steady_timer timer3_(io);
//
//int g_begin = 0; 
//
//void start_time()
//{
//	g_begin = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//	//此地方expires_at()是从起始时间点开始算
//	timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(5));
//
//	timer_.async_wait([](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		auto end = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//		std::cout << end - g_begin << std::endl;
//		end = g_begin;
//		start_time();
//		});
//}
//
//void start_time1()
//{
//	g_begin = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//	timer1_.expires_at(timer1_.expires_at() + std::chrono::seconds(5));
//
//	timer1_.async_wait([](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		auto end = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//		std::cout << end - g_begin << std::endl;
//		end = g_begin;
//		//定时器时间链
//		start_time1();
//		});
//}
//
//void start_time2()
//{
//	g_begin = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//	timer2_.expires_from_now(boost::posix_time::seconds(5));
//
//	timer2_.async_wait([](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		auto end = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//		std::cout << end - g_begin << std::endl;
//		end = g_begin;
//		//定时器时间链
//		start_time2();
//		});
//}
//
//void start_time3()
//{
//	g_begin = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//	timer3_.expires_from_now(std::chrono::seconds(5));
//
//	timer3_.async_wait([](const boost::system::error_code& ec) {
//		if (ec) {
//			return;
//		}
//
//		auto end = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//		std::cout << end - g_begin << std::endl;
//		end = g_begin;
//		//定时器时间链
//		start_time3();
//		});
//}
//
//int main()
//{
//	//start_time();
//	//start_time1();
//	//start_time2();
//	start_time3();
//	io.run();
//}

//#include <iostream>
//#include <windows.h>
//
//void char_to_wchar(const char* ch, std::wstring& w_str)
//{
//	wchar_t* wchar;
//	int len = MultiByteToWideChar(CP_ACP, 0, ch, strlen(ch), NULL, 0);
//	wchar = new wchar_t[len + 1];
//	MultiByteToWideChar(CP_ACP, 0, ch, strlen(ch), wchar, len);
//	wchar[len] = '\0';
//	w_str = wchar;
//	delete[]wchar;
//	wchar = nullptr;
//}
//
//int main()
//{
//	std::string str = "111";
//	std::wstring w_str;
//	char_to_wchar(str.c_str(), w_str);
//	int i = 100;
//}

//#include <iostream>
//#include <windows.h>
//
//class single_application {
//public:
//	~single_application() {
//#ifdef _WIN32_WINNT
//		ReleaseMutex(mutex_);
//#endif
//	}
//
//	bool is_runing(const std::string& mutex_name) {
//#ifdef _WIN32_WINNT
//		mutex_ = OpenMutexA(MUTEX_ALL_ACCESS, 0, mutex_name.c_str());
//		if (nullptr == mutex_)
//		{
//			mutex_ = CreateMutexA(0, 0, mutex_name.c_str());
//			return false;
//		}
//		else
//		{
//			auto out_put = mutex_name + " is running, so exit!\n";
//			std::cout << out_put << std::endl;
//			return true;
//		}
//#else
//		std::cout << "has not realize" << std::endl;
//		return true;
//#endif
//	}
//
//private:
//#ifdef _WIN32_WINNT
//	HANDLE mutex_;
//#endif
//
//};
//
//int main()
//{
//	single_application single;
//	if (single.is_runing("ConsoleApplication2"))
//	{
//		return 0;
//	}
//
//	while (1)
//	{
//	}
//}
//

//#include <iostream>
//#include <string>
//#include <chrono>
//#include <boost/process.hpp>
//#include <boost/asio.hpp>
//
//int main()
//{
//	boost::asio::io_service io;
//	try {
//		//std::string cmd1 = R"("E:/sort/3dmax2018/3ds Max 2018/3dsmax.exe" -Language=CHS -q -silent -mip -u MAXScript "E:/render_temp_path/output_vray_vrscene1.ms")";
//std::string max_path = "E:/sort/3dmax2018/3ds Max 2018/3dsmax.exe";
//std::string ms_path = "E:/render_temp_path/output_vray_vrscene1.ms";
//std::string cmd1 = "\"" + max_path + "\" -Language=CHS -q -silent -mip -u MAXScript \"" + ms_path + "\"";
//		boost::process::ipstream out;
//
//		boost::process::child c(cmd1,boost::process::std_out > out);
//
//		c.wait();
//		//c.wait_for(std::chrono::seconds(5));
//		//boost::asio::steady_timer timers(io);
//		//timers.expires_from_now(std::chrono::seconds(10));
//		//timers.async_wait([&c](const boost::system::error_code& ec) {
//		//	if (ec) {
//		//		return;
//		//	}
//
//		//	if (c.running()){
//		//		c.terminate();
//		//	}
//		//	});
//
//
//		//io.run();
//
//
//		int icode = c.exit_code();
//	}
//
//	catch (std::exception & e) {
//		std::string str = e.what();
//	}
//
//
//}

//#include <iostream>
//#include <boost/process.hpp>
//#include <string>
//
//int main()
//{
//	std::vector<std::string>vec;
//	boost::process::environment evn = boost::this_process::environment();
//
//	int size = evn.size();
//	std::string str = evn.get("ADSK_3DSMAX_SDK_2018");
//	for (auto str : evn) {
//		//系统值
//		std::string strs = str.to_string();
//		//系统变量
//		std::string name = str.get_name();
//		if (!name.empty()){
//			vec.push_back(str.get_name());
//			std::cout << name << std::endl;
//		}
//		
//	}
//
//
//
//	int i = 100;
//
//}

//#include <boost/process.hpp>
//#include <iostream>
//int main()
//{
//	boost::process::ipstream out;
//	boost::process::child c("ps -ef|grep time2 | grep -v grep |wc -l", boost::process::std_out > out);
//	for (std::string line; c.running() && std::getline(out, line);) {
//		std::cout << line << "\n";
//	}
//
//	c.wait();
//}

//#include <iostream>  
//using namespace std;
//
//#include <boost/program_options.hpp>  
//namespace po = boost::program_options;
//
//int main(int argc, char* argv[])
//{
//	//int level;  
//	po::options_description desc("Allowed options");
//	desc.add_options()
//		("help", "produce help message")
//		//("help,h", "produce help message")  
//		("compression", po::value<int>(), "set compression level");
//	//("compression", po::value<int>(&level)->default_value(1), "set compression level");  
//
//	po::variables_map vm;
//	po::store(po::parse_command_line(argc, argv, desc), vm);
//	po::notify(vm);
//
//	if (vm.count("help"))
//	{
//		cout << desc << endl;
//		return 1;
//	}
//
//	if (vm.count("compression"))
//	{
//		cout << "compression level was set to " << vm["compression"].as<int>() << "." << endl;
//		//cout<<"compression level: "<<level<<endl;  
//	}
//	else
//	{
//		cout << "compression level was not set." << endl;
//	}
//
//	return 0;
//}

//#include <iostream>  
//using namespace std;
//#include <boost/program_options.hpp>  
//
//int main(int argc, char* argv[])
//{
//	//int level;  
//	boost::program_options::options_description desc("Allowed options");
//	desc.add_options()
//		("help", "produce help message")
//		//("help,h", "produce help message")  
//		("compression", boost::program_options::value<int>(), "set compression level");
//	//("compression", po::value<int>(&level)->default_value(1), "set compression level");  
//
//	boost::program_options::variables_map vm;
//	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
//	boost::program_options::notify(vm);
//
//	if (vm.count("help"))
//	{
//		cout << desc << endl;
//		return 1;
//	}
//
//	if (vm.count("compression"))
//	{
//		cout << "compression level was set to " << vm["compression"].as<int>() << "." << endl;
//		//cout<<"compression level: "<<level<<endl;  
//	}
//	else
//	{
//		cout << "compression level was not set." << endl;
//	}
//
//	return 0;
//}
//
//
//#include<cstdio>
//#include <string>
//#include <iostream>
//int main()
//{
//
//	FILE* fp;
//	std::string buffer;
//	fp = popen("ps -ef|grep time2 | grep -v grep |wc -l", "r");
//	fread(&buffer[0], 1,1, fp);
//
//	std::cout << buffer << std::endl;
//	pclose(fp);
//}

//#include <iostream>
//
////1900 -2049
//int lunay_info[] =
//{
//0x04bd8, 0x04ae0, 0x0a570, 0x054d5, 0x0d260, 0x0d950, 0x16554, 0x056a0, 0x09ad0, 0x055d2,
//0x04ae0, 0x0a5b6, 0x0a4d0, 0x0d250, 0x1d255, 0x0b540, 0x0d6a0, 0x0ada2, 0x095b0, 0x14977,
//0x04970, 0x0a4b0, 0x0b4b5, 0x06a50, 0x06d40, 0x1ab54, 0x02b60, 0x09570, 0x052f2, 0x04970,
//0x06566, 0x0d4a0, 0x0ea50, 0x06e95, 0x05ad0, 0x02b60, 0x186e3, 0x092e0, 0x1c8d7, 0x0c950,
//0x0d4a0, 0x1d8a6, 0x0b550, 0x056a0, 0x1a5b4, 0x025d0, 0x092d0, 0x0d2b2, 0x0a950, 0x0b557,
//0x06ca0, 0x0b550, 0x15355, 0x04da0, 0x0a5d0, 0x14573, 0x052d0, 0x0a9a8, 0x0e950, 0x06aa0,
//0x0aea6, 0x0ab50, 0x04b60, 0x0aae4, 0x0a570, 0x05260, 0x0f263, 0x0d950, 0x05b57, 0x056a0,
//0x096d0, 0x04dd5, 0x04ad0, 0x0a4d0, 0x0d4d4, 0x0d250, 0x0d558, 0x0b540, 0x0b5a0, 0x195a6,
//0x095b0, 0x049b0, 0x0a974, 0x0a4b0, 0x0b27a, 0x06a50, 0x06d40, 0x0af46, 0x0ab60, 0x09570,
//0x04af5, 0x04970, 0x064b0, 0x074a3, 0x0ea50, 0x06b58, 0x055c0, 0x0ab60, 0x096d5, 0x092e0,
//0x0c960, 0x0d954, 0x0d4a0, 0x0da50, 0x07552, 0x056a0, 0x0abb7, 0x025d0, 0x092d0, 0x0cab5,
//0x0a950, 0x0b4a0, 0x0baa4, 0x0ad50, 0x055d9, 0x04ba0, 0x0a5b0, 0x15176, 0x052b0, 0x0a930,
//0x07954, 0x06aa0, 0x0ad50, 0x05b52, 0x04b60, 0x0a6e6, 0x0a4e0, 0x0d260, 0x0ea65, 0x0d530,
//0x05aa0, 0x076a3, 0x096d0, 0x04bd7, 0x04ad0, 0x0a4d0, 0x1d0b6, 0x0d250, 0x0d520, 0x0dd45,
//0x0b5a0, 0x056d0, 0x055b2, 0x049b0, 0x0a577, 0x0a4b0, 0x0aa50, 0x1b255, 0x06d20, 0x0ada0
//};
//
////计算方式 
////4月29天              4
////0000 0111 1001 0101 0100
//
//// 计算该月总天数
//int getMonthDays(int lunarYeay, int month) {
//	if ((month > 31) || (month < 0)) {
//		return 0;
//	}
//
//	// 0X0FFFF[0000 {1111 1111 1111} 1111]中间12位代表12个月，1为大月，0为小月
//	int bit = 1 << (16 - month);
//	if (((lunay_info[lunarYeay - 1900] & 0x0FFFF) & bit) == 0) {
//		return 29;
//	}else {
//		return 30;
//	}
//}
//
////	计算阴历年闰哪个月 1-12 , 没闰传回 0
//int getLeapMonth(int year) {
//	//取最后四位
//	return (int)(lunay_info[year - 1900] & 0x000f);
//}
//
////	计算阴历年闰月多少天
//int getLeapMonthDays(int year) {
//	if (getLeapMonth(year) != 0) {
//		//取最前4位
//		if ((lunay_info[year - 1900] & 0x0000f0000) == 0) {
//			return 29;
//		}else {
//			return 30;
//		}
//	}
//	else {
//		return 0;
//	}
//}
//
//// 计算阴历年的总天数
//int getYearDays(int year) {
//	int sum = 29 * 12;
//	for (int i = 0x8000; i >= 0x8; i >>= 1) {
//		if ((lunay_info[year - 1900] & 0xfff0 & i) != 0) {
//			sum++;
//		}
//	}
//
//	return sum + getLeapMonthDays(year);
//}
//
//
//
//int main()
//{
//	int index = lunay_info[2020 - 1900];
//	int i = getLeapMonth(2020);
//
//	int day_count = getYearDays(2020);
//
//	int leap_month = getLeapMonthDays(2020);
//}

//#include <iostream>
//#include <boost/format.hpp>
//
//int main()
//{
//	std::string max_path = "111";
//	std::string ss = "22";
//	//注意要两个%，否则会出错
//	boost::format f("%1%export_%2%.flag");
//
//	f% max_path;
//	f% ss;
//	std::string for_str = f.str();
//
//}

//#include <iostream>
//#include <chrono>
//#include <random>
//std::default_random_engine s;
//
//int get_random(int senconds)
//{
//	//1-9随机数
//	std::uniform_int_distribution<int> u(1, senconds-1);
//	return u(s);
//
//}
//int main()
//{
//	std::int64_t time_stramp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//
//	s.seed(time_stramp);
//	for (int i =0;i<10;i++)
//	{
//		std::cout<< 60+get_random(10) <<std::endl;
//	}
//	
//	int i = 100;
//	
//}

//#include <iostream>
//#include <random>
//
//int rand_value(int min, int max)
//{
//	std::random_device rd;   // obtain a random number from hardware
//	std::mt19937 eng(rd());  // seed the generator
//	std::uniform_int_distribution<> distr(min, max);  // define the range int型或unsigned int
//	//std::uniform_real_distribution<float>distr(min, max); //define the range float double long double
//	return distr(eng);
//}
//
//int main()
//{
//	for (int i = 0; i <20; i++) {
//		std::cout << "第"<<i+1<<"次"<<rand_value(1, 100) << std::endl;
//	}
//
//	int i = 100;
//}

//#include <iostream>
//
////判断相等
//template <typename T>
//typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
//equal(T a, T b)
//{
//	if (std::fabs(a-b)<1e-6) {
//		return true;
//	}
//		
//	return false;
//}
//
////判断两个float大小
//template <typename T>
//bool is_big(T a, T b)
//{
//	if (!std::is_same<T,double>::value && !std::is_same<T,float>::value){
//		return false;
//	}
//
//	if (std::fabs(a - b) > 1e-6) {
//		return true;
//	}
//
//	return false;
//}
//
//int main(int argv, char* args[])
//{
//	double d1 = 0.2;
//	double d2 = 1 / std::sqrt(5) / std::sqrt(5);
//
//	float f3 = 1.5f;
//	float f4 = 1.2f;
//	if (is_big("a", "b")){
//		int i = 100;
//	}
//	if (equal(d1,d2)){
//		int i = 100;
//	}
//	std::cout << "d1 = " << d1 << std::endl;
//	std::cout << "d2 = " << d2 << std::endl;
//
//
//	return 0;
//}

//#include <iostream>
//template<typename TYPE>
//void typeCheck(TYPE data)
//{
//	if (std::is_same<TYPE, int>::value)
//	{
//		std::cout << "int type" << std::endl;
//	}
//	//返回bool值
//	else if (std::is_same<TYPE, std::string>::value)
//	{
//		std::cout << "string type" << std::endl;
//	}
//	else
//	{
//		std::cout << "other type";
//	}
//}
//
//int main()
//{
//	int b = 1;
//	int a =b;
//	typeCheck<int >(a);
//}

//#include <iostream>
//#include <boost/asio.hpp>
//boost::asio::io_service io;
//
//boost::asio::deadline_timer de(io, boost::posix_time::seconds(0));
//void start_time()
//{
//	de.expires_at(de.expires_at() + boost::posix_time::seconds(5));
//	de.async_wait([](const boost::system::error_code &ec) {
//		if (ec){
//			return;
//		}
//
//		std::cout << "111" << std::endl;
//		start_time();
//		});
//}
//int main()
//{
//	//post请求
//	//io.post();
//	start_time();
//	io.run();
//	int i = 100;
//}
//#include <iostream>
//#include <string>
//#include "reflect.hpp"
//
//struct MyStruct
//{
//	std::string str;
//	int a;
//};
//
//REFLECTION(MyStruct, a,str)
//
//int main()
//{
///*	meta_info_reflectget_element_names()*/
//	MyStruct my{ "111",2};
//	auto info= meta_info_reflect(my);
//	数组所有的映射内容
//	auto vec = info.get_element_names();
//
//	结构体名
//	std::string str = info.get_class_name();
//
//	auto tuple_ = info.get_element_meta_protype();
//
//	auto sk = std::get<0>(tuple_);
//	reflector::each_object(my, [](MyStruct obj, std::string name, auto type) {
//		std::cout <<obj.a << std::endl;
//		std::cout << typeid(obj.a).name() << std::endl; //  结构体内的地址
//		std::cout << name << std::endl;
//		});
//
//	reflector::find_protype("a", my, [](MyStruct obj, std::string name, auto type) {
//		std::cout << "11" << std::endl;
//		});
//}

//#include <crtdbg.h>  
//
//
//#ifdef _DEBUG  
//#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)  
//#endif  
//
//void EnableMemLeakCheck()
//{
//	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
//}
//
//
//void detect_memory_leaks(bool on_off)
//{
//	int flags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG | _CRTDBG_LEAK_CHECK_DF);
//	if (!on_off)
//		flags &= ~_CRTDBG_LEAK_CHECK_DF;
//	else {
//		flags |= _CRTDBG_LEAK_CHECK_DF;
//		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//	}
//	_CrtSetDbgFlag(flags);
//}
//
//using namespace std;
//int main()
//{
//	EnableMemLeakCheck();
//	//detect_memory_leaks(true);
//	//_CrtSetBreakAlloc(2403);
//	int* ptr = new int;
//	//delete ptr;
//	//ptr = nullptr;
//	//_CrtSetBreakAlloc(556);  
//	//自己的代码
//	//_CrtDumpMemoryLeaks();
//
//}

//#include <iostream>
//#include<typeinfo>
//#include <string>
//
//int main()
//{
//	int i = 100;
//	std::string type_name = typeid(i).name();
//}

//#include <iostream>
//#include <boost/process.hpp>
//#include <regex>
//
//bool find_vray()
//{
//	std::vector<std::string>vec;
//	std::regex e("^([^ ]*)3DSMAX(\\d{4})_MAIN([^ ]*)");
//	std::smatch sub_match;
//	boost::process::environment evn = boost::this_process::environment();
//
//	for (auto str : evn) {
//		//系统变量
//		std::string name = str.get_name();
//		if (!name.empty()) {
//			if (std::regex_match(name, sub_match, e)) {
//				vec.push_back(str.get_name());
//			}
//		}
//	}	
//
//	if (vec.empty()){
//		return false;
//	}
//	
//	return true;
//}
//
//bool find_3dMax_Path()
//{
//	std::vector<std::string>vec;
//	std::regex e("^([^ ]*)ADSK_3DSMAX_x64_([^ ]*)");
//	std::smatch sub_match;
//	boost::process::environment evn = boost::this_process::environment();
//
//	for (auto str : evn) {
//		//系统变量
//		std::string name = str.get_name();
//		if (!name.empty()) {
//			if (std::regex_match(name, sub_match, e)) {
//				vec.push_back(str.get_name());
//			}
//		}
//	}
//
//	if (vec.empty()) {
//		return false;
//	}
//
//	return true;
//}
//
//int main()
//{
//	find_3dMax_Path();
//}

//#include "WinReg.hpp"
//#include <string>
//#include <iostream>
//#include <algorithm>
//#include <filesystem>
//#include <codecvt>  // for codecvt_utf8_utf16
//#include <locale>   // for wstring_convert
//
//#ifdef _MSC_VER
//#pragma warning(disable:4996)
//#endif
//
//using namespace std;
//std::wstring string_to_wstring(const std::string& s)
//{
//	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
//	return conv.from_bytes(s);
//}
//bool HasDVDDrive()
//{
//	char szbuf[MAX_PATH] = { 0 };
//	GetLogicalDriveStringsA(MAX_PATH, szbuf);
//
//	int nCount = 0;
//	char* pDrive = szbuf;
//	for (int nlen = strlen(szbuf); nlen == 3;)
//	{
//		if (GetDriveTypeA(pDrive) == DRIVE_CDROM)
//		{
//			return true;
//		}
//		pDrive += 4;
//		nlen = strlen(pDrive);
//	}
//	return false;
//}
//
//int GetAllDrives(std::vector<std::string>& vecDrives)
//{
//	char szbuf[MAX_PATH] = { 0 };
//	GetLogicalDriveStringsA(MAX_PATH, szbuf);
//
//	int nCount = 0;
//	char* pDrive = szbuf;
//	for (std::size_t nlen = strlen(szbuf); nlen == 3; nCount++)
//	{
//		//网络盘
//		if (GetDriveTypeA(pDrive) == DRIVE_FIXED )
//		{
//			std::string strDrive = pDrive;
//			vecDrives.push_back(strDrive);
//		}
//
//		pDrive += 4;
//		nlen = strlen(pDrive);
//	}
//	return nCount;
//}
//
//std::wstring getWorkingPath() {
//
//	const std::wstring testSubKey = L"Software\\ZheJiangZhiWangTech\\DBRenderClient";
//	winreg::RegKey key{ HKEY_CURRENT_USER, testSubKey };
//
//	try
//	{
//		std::wstring path = key.GetStringValue(L"working_path");
//		if (!path.empty()) {
//			return path;
//		}
//	}catch (...)
//	{
//
//		std::vector<std::string>vecs;
//		GetAllDrives(vecs);
//		int count = vecs.size();
//
//		std::vector<std::pair<int, std::int64_t>>disk_vecs;
//
//		int index = 0;
//		for (int i = 0; i < count; i++) {
//			//得出磁盘的可用空间
//			DWORD dwTotalClusters;//总的簇
//			DWORD dwFreeClusters;//可用的簇
//			DWORD dwSectPerClust;//每个簇有多少个扇区
//			DWORD dwBytesPerSect;//每个扇区有多少个字节
//			BOOL bResult = GetDiskFreeSpace(string_to_wstring(vecs[i].c_str()).c_str(), &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);
//			if (bResult) {
//				int bytes_available = dwFreeClusters * (DWORD64)dwSectPerClust * (DWORD64)dwBytesPerSect;
//				disk_vecs.push_back({ i,bytes_available });
//			}
//		}
//
//		std::sort(disk_vecs.begin(), disk_vecs.end(), [](std::pair<int, std::int64_t>p1, std::pair<int, std::int64_t>p2)->bool {return p1.second > p2.second; });
//		std::string disk_str = vecs[disk_vecs[0].first] + "render_temp_path1";
//
//		if (!std::filesystem::exists(disk_str)){
//			std::filesystem::create_directories(disk_str);
//		}
//		key.SetStringValue(L"working_path",string_to_wstring(disk_str));
//	}
//}
//
//void get_open_file_names(std::vector<std::wstring>& vecs)
//{
//	wchar_t sz_path_name[MAX_PATH] = { 0 };
//	std::wstring sz_path;
//	OPENFILENAMEW open_file_name = {};
//	open_file_name.lStructSize = sizeof(OPENFILENAMEW);
//	open_file_name.nMaxFile = MAX_PATH;//这个必须设置，不设置的话不会出现打开文件对话框  
//	open_file_name.lpstrFilter = L"文本文件 任何文件（*.max*）\0*.*\0";
//	open_file_name.lpstrFile = sz_path_name;
//	open_file_name.nFilterIndex = 1;
//	open_file_name.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR | OFN_ALLOWMULTISELECT;
//
//	if (GetOpenFileName(&open_file_name)) {
//		sz_path.resize(open_file_name.nFileOffset-1);
//		lstrcpyn(&sz_path[0], sz_path_name, open_file_name.nFileOffset);
//		sz_path += L"\\";
//
//		wchar_t* p = sz_path_name + open_file_name.nFileOffset; //把指针移到第一个文件
//		while (*p) {
//			std::wstring w_path = sz_path;
//			w_path += p;
//			vecs.push_back(w_path);
//			p += lstrlen(p) + 1;     //移至下一个文件
//		}
//	}
//}
//
//int main()
//{
//	std::string path = "E:\\render_temp_path\\Camera001.vrscene";
//	//std::string scene_name = std::filesystem::path(path).filename().string();
//	//std::string path11 = std::filesystem::path(path).parent_path().string();
//	//std::string  destPath_ =std::filesystem::path(path).parent_path().string() + "/"+std::filesystem::path(path).stem().string();
//	//std::string file_name = std::filesystem::path("E:/render_temp_path/Camera001/Camera001.vrscene").filename().string();
//	//std::wstring www = L"E:\\";
//	//www+= L"\\";
//	//std::vector<std::wstring>vecs;
//	//get_open_file_names(vecs);
//	////std::vector<std::string>vecs;
//	////GetAllDrives(vecs);
//	//std::string ss = std::filesystem::relative("E:\\").string();
//	//getWorkingPath();
//}
//
//				 
//#include <iostream>
//#include <filesystem>
//#include <boost/process.hpp>
//struct max_vision_info {
//	int version = 0;
//	std::string path;
//};
//
//std::vector<max_vision_info> get_3dmax_versions()
//{
//	boost::process::environment ev = boost::this_process::environment();
//	std::vector <max_vision_info> version_vecs;
//	for (int year = 2011; year < 2050; year++) {
//		const std::string env_name = "ADSK_3DSMAX_x64_" + std::to_string(year);
//		std::string path = ev.get(env_name);
//		if (path.empty()){
//			continue;
//		}
//
//		max_vision_info info;
//		info.path = path;
//		info.version = year;
//		version_vecs.push_back(info);
//	}
//	return version_vecs;
//}
//
//int main()
//{
//	if (std::filesystem::remove("E:/111.txt")){
//		int i = 100;
//	}
//	
//	std::wstring ws = L"E:/111";
//	std::string path = std::filesystem::path(ws).string();
//	get_3dmax_versions();
//}

/*************windows下获取对话框下的多个文件************************/
//#include <iostream>
//#include <windows.h>
//#include <vector>
//void get_open_file_names(std::vector<std::wstring>&vecs)
//{
//	wchar_t szPathName[MAX_PATH] = { 0 };
//	wchar_t szPath[MAX_PATH] = { 0 };
//	wchar_t szFileName[80 * MAX_PATH] = { 0 };
//	OPENFILENAMEW openFileName = {};
//	openFileName.lStructSize = sizeof(OPENFILENAMEW);
//	openFileName.nMaxFile = MAX_PATH;//这个必须设置，不设置的话不会出现打开文件对话框  
//	openFileName.lpstrFilter = L"文本文件 任何文件（*.max*）\0*.*\0";
//	openFileName.lpstrFile = szPathName;
//	openFileName.nFilterIndex = 1;
//	openFileName.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR | OFN_ALLOWMULTISELECT;
//
//	if (GetOpenFileName(&openFileName))
//	{
//
//		lstrcpyn(szPath, szPathName, openFileName.nFileOffset);
//
//		szPath[openFileName.nFileOffset] =0;
//		int nLen = lstrlen(szPath);
//
//		if (szPath[nLen - 1] != '\\')   
//		{
//			lstrcat(szPath, TEXT("\\"));
//		}
//
//		wchar_t* p = szPathName + openFileName.nFileOffset; //把指针移到第一个文件
//
//		while (*p)
//		{
//			ZeroMemory(szFileName, sizeof(szFileName));
//			lstrcat(szFileName, szPath);  //给文件名加上路径  
//			lstrcat(szFileName, p);    //加上文件名    
//			vecs.push_back(szFileName);
//			p += lstrlen(p) + 1;     //移至下一个文件
//		}
//	}
//}
//
//int main()
//{
//	std::vector<std::wstring>vecs;
//	get_open_file_names(vecs);
//	int si = 0;
//}

//#include <iostream>
//
//int main(int argc, char** argv)
//{
//	std::string ss = "11";
//	if (!ss.empty()){
//		int i = 100;
//	}
//}

//#include <iostream>
//#include <filesystem>
//#include <string>
//#include <time.h>
//#include <string>
//#include <filesystem>
//#include <windows.h>
//#include <DbgHelp.h>
//#include <chrono>
//#pragma comment(lib, "DbgHelp.lib")
//#pragma warning(disable:4996)
//
//const std::string g_dump_dir = "./dump";
//const std::string g_dump_name = "/test_dump_";
//
// std::int64_t get_time_stamp()
// {
//	 std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
//	 auto tmp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
//	 return tmp.count();
// }
//
// std::tm* gettm(int64_t timestamp)
// {
//	 int64_t milli = timestamp + (int64_t)8 * 60 * 60;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//	 auto mTime = std::chrono::seconds(milli);
//	 auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>(mTime);
//	 auto tt = std::chrono::system_clock::to_time_t(tp);
//	 std::tm* now = std::gmtime(&tt);
//	 return now;
// }
//
// std::string all_tm_to_str(std::tm* ptm,std::string format_str)
// {
//	 char date[60] = { 0 };
//	 sprintf(date, format_str.c_str(),
//		 (int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
//		 (int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);
//	 return std::string(date);
// }	
//
// std::string date_tm_to_str(std::tm* ptm, std::string format_str)
// {
//	 char date[60] = { 0 };
//	 sprintf(date, format_str.c_str(),
//		 (int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday);
//	 return std::string(date);
// }
//
// std::string time_tm_to_str(std::tm* ptm, std::string format_str)
// {
//	 char date[60] = { 0 };
//	 sprintf(date, format_str.c_str(),(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);
//	 return std::string(date);
// }
//
// LONG ExceptionCrashHandler(EXCEPTION_POINTERS* pException)
// {
//	 std::int64_t time_stamp = get_time_stamp();
//	 std::string dump_dir = g_dump_dir +"/"+ date_tm_to_str(gettm(time_stamp),"%d-%02d-%02d");
//	 if (!std::filesystem::exists(dump_dir))
//	 {
//		 std::filesystem::create_directories(dump_dir);
//	 }
//	 std::string dump_name = dump_dir;
//	 dump_name += g_dump_name;
//	 dump_name += time_tm_to_str(gettm(time_stamp), "%02d时%02d分%02d秒");
//	 dump_name += ".dmp";
//	 // 创建Dump文件
//	 HANDLE hDumpFile = CreateFileA(dump_name.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//	 // Dump信息
//	 MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
//	 dumpInfo.ExceptionPointers = pException;
//	 dumpInfo.ThreadId = GetCurrentThreadId();
//	 dumpInfo.ClientPointers = TRUE;
//	 // 写入Dump文件内容
//	 MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);
//	 CloseHandle(hDumpFile);
//	 return EXCEPTION_EXECUTE_HANDLER;
// }
//
//
//int main()
//{
//
//::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ExceptionCrashHandler);
//
//	strcpy(NULL, "adfadfg");
//
//}


//#include <iostream>
//#include<ctime>
//#include <chrono>
//#pragma warning(disable:4996)
//
//std::int64_t get_time_stamp()
//{
//	std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> tp = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
//	auto tmp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
//	return tmp.count();
//}
//
//std::int64_t get_mill_time_stamp() {
//	std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//	auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
//	return tmp.count();
//}
//
//std::tm* gettm(int64_t timestamp)
//{
//	int flag = 0;  
//	std::int64_t temp_time_stamp = timestamp;
//	std::tm* now = nullptr;
//	while (temp_time_stamp > 10)
//	{
//		temp_time_stamp = temp_time_stamp / 10;
//		flag++;
//	}
//
//	//秒
//	if (flag ==9){
//		int64_t milli = timestamp + (int64_t)8 * 60 * 60;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//		auto mTime = std::chrono::seconds(milli);
//		auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>(mTime);
//		auto tt = std::chrono::system_clock::to_time_t(tp);
//		now = std::gmtime(&tt);
//	}else if(flag == 12) {	//毫秒
//		int64_t milli = timestamp + (int64_t)8 * 60 * 60 * 1000;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
//		auto mTime = std::chrono::milliseconds(milli);
//		auto tp = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(mTime);
//		auto tt = std::chrono::system_clock::to_time_t(tp);
//		now = std::gmtime(&tt);
//	}
//
//	return now;
//}
//
//std::string all_tm_to_str(std::tm* ptm, std::string format_str)
//{
//	char date[60] = { 0 };
//	sprintf(date, format_str.c_str(),
//		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
//		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);
//	return std::string(date);
//}
//int main()
//{
//	std::int64_t time_stamp = get_mill_time_stamp();
//	std::string str = all_tm_to_str(gettm(time_stamp),"%d-%02d-%02d %02d:%02d:%02d");
//}


//#include <boost/asio.hpp>
//boost::asio::io_service io;
////boost::asio::ip::tcp::acceptor ac(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8888));
//boost::asio::ip::tcp::acceptor ac(io);
//boost::asio::ip::tcp::endpoint end(boost::asio::ip::tcp::v4(), 8888);
//
//void accpect()
//{
//	std::shared_ptr<boost::asio::ip::tcp::socket> sock_client_ptr(new boost::asio::ip::tcp::socket(io));
//	ac.async_accept(&sock_client_ptr, [&sock_client_ptr]( const boost::system::error_code& ec) {
//		if ( ec ){
//			return;
//		}
//
//		accpect();
//		});
//}
//
//int main()
//{
//	ac.open(end.protocol());
//	ac.bind(end);
//
//	ac.listen();
//	ac.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
//	accpect();
//
//	io.run();
//}

//#include <iostream>
//#include <boost/asio.hpp>
//boost::asio::io_service io;
//boost::asio::ip::tcp::endpoint end(boost::asio::ip::tcp::v4(), 8888);
//
//
////自动识别服务器的ip
////boost::asio::ip::tcp::acceptor ac(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8888));
//boost::asio::ip::tcp::acceptor ac(io);
//
//void MakeSession()
//{
//	std::shared_ptr<boost::asio::ip::tcp::socket> sock_client_ptr(new boost::asio::ip::tcp::socket(io));
//	ac.async_accept(*sock_client_ptr, [sock_client_ptr](const boost::system::error_code &ec) {
//		if (ec) {
//			return;
//		}
//
//		//必须连接上才能设置当前socket的属性
//		sock_client_ptr->set_option(boost::asio::ip::tcp::socket::reuse_address(true));
//		std::cout << sock_client_ptr->remote_endpoint().address().to_string() << std::endl;
//		//造成socket阻塞，可能是因为io输出口的问题
//		//std::cout << sock_client_ptr->remote_endpoint().address()<< std::endl;
//		MakeSession();
//		});
//}
//
//int main()
//{
//	ac.open(end.protocol());
//	ac.bind(end);
//
//	ac.listen();
//	ac.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
//
//	MakeSession();
//
//	//注意地方:若被io_service被stop掉之后,再次启动run的话，一定要调io.reset()接口
//	//io.stop();
//	io.reset();
//	io.run();
//}

#include <iostream>

int main()
{

}