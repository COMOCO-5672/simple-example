#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <utility>

int main()
{
    std::map<std::string, std::string> m_list;
    m_list.insert(std::pair<std::string, std::string>("11", "22"));
    m_list.insert(std::pair<std::string, std::string>("44", "33"));

    const auto find_item = std::find_if(m_list.begin(), m_list.end(), [](const std::map<std::string, std::string>::value_type item)
                                        { return item.second == "22"; });
    if (find_item != m_list.end())
    {
        printf(find_item->first.c_str());
    }

    system("PAUSE");
    return 0;
}