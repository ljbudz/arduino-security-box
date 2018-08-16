# arduino-security-box

The servo blocks the door of the box from opening as a default. When the game begins, random arrows move across the top line of the LCD screen with a marker on the bottom line. When the arrow moves above the marker, the user must push the joystick in the corresponding direction. If the user does this correctly, the green LEDs will flash. If not, the red LEDs will flash and a message will indicate that the game has ended. The user must complete 4 levels of the game in which the speed of the arrows increases each time. If the user successfully matches all the arrows in every level, a message will appear indicating the the box will unlock. The servo motor will then move 90 degrees, allowing the door to be opened. Resetting the Arduino will lock the box again and restart the game.  

Note: Use the "lock_unlock" code to manually lock and unlock the box.
