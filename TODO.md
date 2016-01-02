Add:
- Return-support when passing from command line

- Better error handling.

- ~~PyMail CLI using ncurses in C~~ (working on this)
 
- ~~Send emails~~

- ~~Receive emails~~

- Configure PyMail

- Add in-UI help

- Update README.md

- ~~'Sending...' statement while waiting for pymail to send the email.~~

- (better) error handling in pymail_cli

Test:

Fix:
- Text overwriting the box when sending email.

- Subject text overwriting the box and 'Body: ' when sending email.

- Not being able to use an enter in the body of your email (Maybe by making
  a seperate button you have to select to send instead of whenever enter is pressed?)

- Displaying received emails

Optimize:
- Everything
