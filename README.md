# PyMail
A simple command line based email client written in Python.

This new program is based on my old python email client which you can find here: https://github.com/Tijndagamer/Python_Email_Client

# Installation

First, clone the repo:

    git clone https://github.com/Tijndagamer/PyMail.git
    
Then make config and pymail executable:

    cd PyMail/src
    chmod +x config
    chmod +x pymail
    
Then you can move pymail to ~/bin/ so you can use it everywhere:

    mv pymail ~/bin/
    
You can also run the config and move the files generated by the config file to ~/bin/ so that you don't have to re enter your credentials everytime, but please note that the files generated by config **are not encrypted or protected.**