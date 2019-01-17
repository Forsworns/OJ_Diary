void splitString(const std::string &s, std::vector<std::string> &v, const std::string &c)
{
	//工具函数，按某个字符串划分string，存入vector中
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (pos2 != string::npos)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}