Windows上で.shファイル (Linuxのシェルスクリプト)を使うための覚書

*なぜかPowerShellにはhoge.exeの出力が一切表示されない。コマンドプロンプトを使うべし。
*以下すべてPowerShellはコマンドプロンプトに読み替え。

<準備編>
0. Editorでソースコード(hoge.sh)の改行が"CRLF(\r\n)"ではなく"LF(\n)"になっていることを確認する。
   VScodeの場合、右下のバナー部にあるのでクリックして変更

1. WSLのインストール - from app store. 20220726時点ではUbuntsuが入っている

2. PowerShell起動

3. PowerShellで　>bash とタイプ. Linuxに入る。

4. Linuxのhome directoryに移動(cdコマンド)

5. 次のコマンドを入力して、Linuxのhome directoryから Windows の適当な場所にジャンプできるようにしておく(シンボリックリンク)

ln -s /mnt/c/Users/catma/Documents/ .

6. これにより、linuxのhome directoryから一発で　"cd Documents"のように移動できる。

内部的にはLinuxとwindowsは別のデバイスなので、このシンボリックリンク作成をしないと中身が見えない。
正確には、"/mnt/"の部分がデバイスのマウントを介して違うデバイスを見ている。
なのでたとえば"cd /mnt/c/Users/catma/"などと書くとLinuxからWindowsのフォルダにアクセスできる。

	7. IntelCompilerのために、次のコマンドを実行
	$ C:\"Program Files (x86)"\Intel\oneAPI\setvars.bat

<実行編>
$bash hoge.sh を入力するだけ。

なお	
linuxからwindowsのexeファイルはそのまま呼び出せる。->嘘やんけ
$./huga.exe
でうんともスントも言わない
