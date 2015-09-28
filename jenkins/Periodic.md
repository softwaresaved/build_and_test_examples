Configure a job to run periodically
===================================

Jenkins can be configured to run jobs periodically. For example:

* Select a project.
* Click Configure.
* Under the Build Triggers heading, click Build periodically.
* A Schedule form will appear. The general format for entries in this form is:

```
MINUTE HOUR DAY_OF_MONTH MONTH DAY_OF_WEEL
```

* So, enter the following to run the job every 2 minutes (Click on the "?" icon to see a complete description of the options available):

```
*/2 * * * *
```

* Click Apply.
* Click ENABLE AUTO REFRESH on the top-right of the Jenkins page, if it has not already been clicked. If it has you'll see DISABLE AUTO REFRESH, so just leave it be.
* Now sit back and you should see new jobs appear in the Build History every 2 minutes.

As another example, we could set up a simple job to regularly ping a URL to see if it is still available. The [ADMIIRE](http://www.admire-project.eu/) project did this to ensure their service end-points were live. Jenkins provided them with a means to check and display service availability in a simple, visually useful way.
