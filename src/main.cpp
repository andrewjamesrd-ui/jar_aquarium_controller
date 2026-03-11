 (cd "$(git rev-parse --show-toplevel)" && git apply --3way <<'EOF' 
diff --git a/AI_Controller_Mark_II.ino b/src/main.cpp
similarity index 51%
rename from AI_Controller_Mark_II.ino
rename to src/main.cpp
index d798efeae42c8991d96b25fff1c8d02db64c5032..79992e405edbf163d9ce22b44a31dfd594602944 100644
--- a/AI_Controller_Mark_II.ino
+++ b/src/main.cpp
@@ -1,22 +1,26 @@
-#include "display.h"
+#include "Display.h"
 #include "ui.h"
 #include "system.h"
 #include "flow.h"
+#include "scheduler.h"
 
 void setup()
 {
   Serial.begin(115200);
 
   initDisplay();
   initSystem();
-  initUI();
   initFlowSensor();
+  initUI();
+
+  initScheduler();
+
+  addTask(updateSystem, 500);
+  addTask(updateFlow, 200);
+  addTask(updateUI, 250);
 }
 
 void loop()
 {
-  updateSystem();
-  updateUI();
-  updateFlow();
-
-}
\ No newline at end of file
+  runScheduler();
+}
 
EOF
)
