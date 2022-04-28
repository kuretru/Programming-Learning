public class Solution {
    /**
     * 验证IP地址
     *
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    public String solve(String IP) {
        if (IP.contains(".") && parseIPv4(IP)) {
            return "IPv4";
        } else if (IP.contains(":") && parseIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }

    private boolean parseIPv4(String ip) {
        String[] segments = ip.split("\\.");
        if (segments.length != 4 || ip.startsWith(".") || ip.endsWith(".")) {
            return false;
        }
        for (String segment : segments) {
            for (int i = 0; i < segment.length(); i++) {
                if (!Character.isDigit(segment.charAt(i))) {
                    return false;
                }
            }
            if (segment.length() > 1 && segment.charAt(0) == '0') {
                return false;
            }
            int value = Integer.parseInt(segment);
            if (value < 0 || value > 255) {
                return false;
            }
        }
        return true;
    }

    private boolean parseIPv6(String ip) {
        ip = ip.toLowerCase();
        String[] segments = ip.split(":");
        if (segments.length != 8 || ip.startsWith(":") || ip.endsWith(":")) {
            return false;
        }
        for (String segment : segments) {
            if (segment.length() > 4 || segment.length() == 0) {
                return false;
            }
            for (int i = 0; i < segment.length(); i++) {
                if (!Character.isDigit(segment.charAt(i)) && !('a' <= segment.charAt(i) && segment.charAt(i) <= 'f')) {
                    return false;
                }
            }
        }
        return true;
    }
}
