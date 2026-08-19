# build_deb.sh 1.0

# Description
build_deb.sh is an application packaging tool. It requires an input application configuration json file(app.json), and generates a .deb application installation package.

the sample app.json: samples/sample_c++/platform/linux/insight_box/app_json/app.json
app.json filling specification:
please refer to samples/sample_c++/platform/linux/insight_box/app_json/README.md

# Environment Dependencies
Python 3 environment is required;
dpkg tool is required.

# Usage
    build_deb.sh -i input app.json file
        [-o output deb file path]
        [-h help]"
    Options:
    "  -h        Show this help message and exit"
    "  -i        Specify input app.json file"
    "  -o        Specify build deb file path"

    Examples:
      build_deb.sh -i ../../samples/sample_c++/platform/linux/insight_box/app_json/app.json           Generate .deb application installation package under the current path
      build_deb.sh -i ../../samples/sample_c++/platform/linux/insight_box/app_json/app.json -o deb    Generate .deb application installation package under the specified path(deb)
