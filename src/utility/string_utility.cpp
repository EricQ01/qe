#pragma once
#include <vector>
#include <sstream>
#include <algorithm>
#include "string_utility.h"


namespace Q {
	std::string trim(std::string_view str, std::string_view delims) {
		if (str.empty()) return std::string("");
		size_t first = str.find_first_not_of(delims);
		size_t last = str.find_last_not_of(delims);
		if (first == size_t(-1)) return std::string("");
		return std::string{ str.substr(first, (last - first + 1)) };
	}

	std::vector<std::string> split(const std::string_view& s, char delim) {
		std::vector<std::string> strings;
		std::stringstream ss{ std::string(s) };
		std::string str;
		while (std::getline(ss, str, delim)) {
			strings.push_back(str);
		}
		return strings;
	}

	std::vector<std::string> split1(const std::string& str, const std::string& delims) {
		std::vector<std::string> output;
		auto first = std::cbegin(str);

		while (first != std::cend(str)) {
			const auto second = std::find_first_of(first, std::cend(str), std::cbegin(delims), std::cend(delims));
			if (first != second)
				output.emplace_back(first, second);

			if (second == std::cend(str))
				break;

			first = std::next(second);
		}
		return output;
	}
	std::vector<std::string> split(const std::string_view& str, const std::string_view& delim) {
		std::vector<std::string> output;
		auto first = std::cbegin(str);
		size_t pos{};
		const auto end = str.size() - delim.size();
		while (pos < end) {
			const auto index = str.find(delim, pos);
			if (index == std::string::npos) break;
			if (index != pos)
				output.emplace_back(str.substr(pos, index - pos));
			pos = index + delim.size();
		}
		if (pos != str.size()) {
			output.emplace_back(str.substr(pos, str.size() - pos));
		}
		return output;
	}

	std::vector<std::string> split_once(const std::string& s, char delim) {
		std::vector<std::string> strings;
		if (auto result = std::ranges::find(s, delim); result != s.end()) {
			strings.emplace_back(s.begin(), result);
			strings.emplace_back(result + 1, s.end());
			return strings;
		}
		strings.push_back(s);
		return strings;
	}

	std::string replace_all(std::string str, std::string_view from, std::string_view to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}
}