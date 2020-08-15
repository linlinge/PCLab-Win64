mv main_panel/debug ..
mv main_panel/release ..
git add .
git commit -m "update"
git push origin master
mv ../debug main_panel/
mv ../release main_panel/
