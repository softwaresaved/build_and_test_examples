Installing Jenkins
=================

This page provides a brief introduction to installing Jenkins. For full information, see the  [Jenkins](http://jenkins-ci.org) web site.

Prerequisites
-------------

**Java JDK and JRE**:

To check if Java JDK and JRE are installed already:

```
$ javac -version
javac 1.6.0_24

$ java -version
java version "1.6.0_24"
OpenJDK Runtime Environment (IcedTea6 1.11.3) (6b24-1.11.3-1ubuntu0.11.04.1)
OpenJDK Client VM (build 20.0-b12, mixed mode, sharing)
```

Output may vary depending on the Java implementation e.g. for Oracle:

```
$ javac -version
javac 1.7.0_60

$ java -version
java version "1.7.0_60"
Java(TM) SE Runtime Environment (build 1.7.0_60-b19)
Java HotSpot(TM) 64-Bit Server VM (build 24.60-b09, mixed mode)
```

If Java JDK and JRE are not installed, then see one of:

* [Oracle Java](http://www.oracle.com/technetwork/java/javase/overview/index.html).
* [OpenJDK Java](http://openjdk.java.net/).

Download Jenkins
----------------

The current version of Jenkins can be downloaded from [Jenkins](http://jenkins-ci.org) or, via the command-line:

From the command-line you can get it by running:

```
$ wget http://mirrors.jenkins-ci.org/war/latest/jenkins.war
```

To see which version of Jenkins you have, run:

```
$ java -jar jenkins.war --version
Running from: $HOME/jenkins.war
webroot: $user.home/.jenkins
1.631
```

Deploy Jenkins
--------------

Jenkins is provided as a web archive, WAR file, `jenkins.war`. It can be deployed into a servlet container e.g. [Apache Tomcat](http://tomcat.apache.org/). However, it also comes with its own web server and can be used stand-alone. So, to start up Jenkins run:

```
$ java -jar jenkins.war
```

This uses a default configuration file directory of `.jenkins`. If you are unhappy with this, or want to use a different directory, then move `.jenkins` to the location you prefer and set a `JENKINS_HOME` environment variable to point to this location e.g.

```
$ mv .jenkins $HOME/jenkins-config
$ export JENKINS_HOME=$HOME/jenkins-config
```

Jenkins uses the default port of 8080. To use a different port, run:

```
$ java -jar jenkins.war --httpPort=9090
```

For all of Jenkins start-up options, run:

```
$ java -jar jenkins.war --help
```

When you start Jenkins for the first time, it will show the following:

```
Jenkins initial setup is required. An admin user has been created and a password generated.
Please use the following password to proceed to installation:
```

It will then print a password, which you should take note of.

View Jenkins
------------

Once Jenkins has started, browse to the URL and port which you started Jenkins with. For example, if you started Jenkins stand-alone with the default port then browse to http://localhost:8080.

If you specified another port e.g. `9090`, then browse to http://localhost:9090.

You should see the Jenkins front page which will prompt you to "Unblock Jenkins".

You will be prompted for your password, so enter it into the Administrator password box.

Click Continue.

Click Install suggested plugins. 

You may now have to wait a while for the plugins to install.

Once installed, follow the on-screen instructions.


