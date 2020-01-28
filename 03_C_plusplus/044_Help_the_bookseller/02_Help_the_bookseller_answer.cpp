class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);
};

std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories) {
  if (lstOfArt.empty() || categories.empty()) return "";
  
  std::map<char, int> sum;
  
  for (auto i : lstOfArt) {
    sum[i[0]] += std::stoi(i.substr(i.find(" ")));
  }
  
  std::string result = "";
  for (auto i : categories) {
    result = result
      + (result.empty() ? "" : " - ")
      + "(" + i + " : " + std::to_string(sum[i[0]]) + ")";
  }
  
  return result;
}