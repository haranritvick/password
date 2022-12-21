Use Security pin as 6069 to update the password.

My project is based on password management in net-banking /internet-banking. When a user wants to change his password, he should enter a new password which is different from the last three password that were changed previously. In case, if the user enters the new password which is same as that of the last three passwords, then a message alert should be displayed to the user stating that 'The new password should be different from the last three passwords changed'.
For example:
 If the user is updating his password for the first time, then he can enter any password of his wish.
 If the user wishes to change his password for the 2nd time, then his new password should be different from only 1st password since, there is only one password stored in the queue.
 If the user changes the password for the third time, then his password should be different from the recently changed two passwords.
 If the last four passwords of a user are p1, p2, p3 and p4, then the new password to be entered should not be p2, p3, p4 and can be p1.

Data Structure: Queue using linked list.

The best possible data structure that I can use to finish this project efficiently is 'Queue using linked list'. The reason behind my choice is that I can save the new passwords in a queue by enqueuing. My queue contains atmost three nodes. So, the time complexity is of constant time i.e., O(1). If the user is updating his password for the first time, then the password will be enqueued in the queue. If he changes the password for the second time following the instructions provided, then the newly updated password is also enqueued into the queue. Similarly, same is done with the third time. If the user wishes to change his password for the fourth time, then the first password entered is dequeued. Now, the password to be entered next time will be checked with the three passwords in the queue. My main theme is to make sure that the queue stores only the recently changed three passwords.
