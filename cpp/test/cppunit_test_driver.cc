// Copyright 2014-2015 The University of Edinburgh.
//
// Licensed under the Apache License, Version 2.0 (the "License"); 
// you may not use this file except in compliance with the License. 
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software 
// distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

#include <stdio.h>
#include <string.h>

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

/*
 * Set up and run tests.
 *
 * @return 0 if successful else 1.
 */
int main() 
{
  // Set up result collection.
  CppUnit::TestResult controller; 
  CppUnit::TestResultCollector result; 
  controller.addListener(&result); 
  CppUnit::BriefTestProgressListener progressListener;
  controller.addListener(&progressListener);

  std::ofstream xmlout("TestResults.xml"); 
  CppUnit::XmlOutputter xmlOutputter (&result, xmlout); 
  CppUnit::TextOutputter consoleOutputter (&result, std::cout); 

  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry =
    CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest(registry.makeTest());

  runner.run(controller); 
  
  xmlOutputter.write(); 
  consoleOutputter.write(); 

  return result.wasSuccessful() ? 0 : 1; 
}
