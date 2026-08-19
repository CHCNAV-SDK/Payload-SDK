# app.json 1.1

app.json is a necessary application configuration file for generating the .deb application installation packgae.

# app.json filling specification:

## Documentation
please visit Related URL, to be filled in, please refer to the following description.

Description of the tags in the app.json configuration file：

## user_app_id
    * Description:
        The APP ID is the unique identifier for the application.
        It is used to ensure the uniqueness of the application, and it must match the generated APP ID.
    * Data type:
        String


## firmware_version
    * Description:
        App version, used for displaying application version information to users. 
        It consists only of numbers and dots, following the four-segment format xx.xx.xx.xx, where each segment can range from 0 to 99.
    * Data type:
        String

## is_ai_rendering
    * Description:
        Indicates whether the application uses AI rendering on the pilot.
        If it does, fill in true; if not, fill in false. 
        If left blank, the default value is true.
    * Data type:
        string

## platform
    * Description:
        Indicates the operating platform of the application. Supported values are:
            * Insight Box, which means the application will run on the Insight Box device.
    * Data type:
        string

## name_cn
    * Description:
        Indicates the Chinese name of the application, which can be customized and should be a string not exceeding 47 bytes in length. 
        It is recommended that the application name has a connection to its functionality, and you should try to avoid duplication with other application names.
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to Chinese, this field will display the application name.
    * Data type:
        string

## name_en
    * Description:
        Indicates the English name of the application, which can be customized. The filling rules are as follows:
            * Maximum length limit is 32 bytes.
            * Only allow letters(a-zA-Z), numbers(0-9), hyphens(-), and dots(.), no other characters are permitted, and it must begin with a letter or number.
            * It cannot be "null".
        It is recommended that the application name has a connection to its functionality, and you should try to avoid duplication with other application names.
        It is advisable to avoid changing the application name afterward. 
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to English, or other languages that are not Chinese, Japanese, or French.
    * Data type:
        string


## description_cn
    * Description:
        Indicates the Chinese description of the application, which should be a string not exceeding 367 bytes in length, containing a detailed custom description of the application.
        The specific filling rules are as follows:
            * Each item within the brackets [] represents the content of each line, with the next item representing the content of the next line. If a line break is needed, multiple items can be filled in within the brackets [].
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to Chinese, this field will display the application description.
    * Data type:
        string

## description_en
    * Description:
        Indicates the English description of the application, which should be a string not exceeding 367 bytes in length, containing a detailed custom description of the application, and it cannot be "null".
        The specific filling rules are as follows:
            * Each item within the brackets [] represents the content of each line, with the next item representing the content of the next line. If a line break is needed, multiple items can be filled in within the brackets [].
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to English, or other languages that are not Chinese, Japanese, or French, this field will display the application description.
    * Data type:
        string

## maintainer_cn
    * Description:
        Indicates the developer information of the application in Chinese, which should be a string not exceeding 127 bytes in length.
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to Chinese, this field will display the developer information of the application.
    * Data type:
        string

## maintainer_en
    * Description:
        Indicates the developer information of the application in English, which should be a string not exceeding 127 bytes in length, and it cannot be "null".
        This field can be used to display application information, such as in the application management interface, when the PILOT language is set to English, or other languages that are not Chinese, Japanese, or French, this field will display the developer information of the application.
    * Data type:
        string

## ver_min
    * Description:
        Indicates the minimum version of the Insight Box device firmware package required for the application to run properly.
        If the firmware package version of the Insight Box device is lower than this version, the application will not be able to install correctly.
        The value is in the format of xx.xx.xx.xx, where each segment can range from 0 to 99.
    * Data type:
        string

## ver_max
    * Description:
        Indicates the maximum version of the Insight Box device firmware package required for the application to run properly.
        If the firmware package version of the Insight Box device is higher than this version, the application will not be able to install correctly.
        The value is in the format of xx.xx.xx.xx, where each segment can range from 0 to 99.
    * Data type:
        string

## bin
    * Description:
        The relative path of the executable bin file generated by the compilation, indicating the application executable bin file.
        It must be a relative path, specifically the path relative to the app.json file, and there must be a corresponding bin file present at that path.
    * Data type:
        string

## userconfig
    * Description:
        The relative path of the relevant files that need to be read at runtime by the application, which is not integrated into the bin file.
        It must be a relative path, specifically the path relative to the app.json file, and there must be corresponding files present at that path.
        If there are no relevant files, this field can be left blank.
    * Data type:
        string

