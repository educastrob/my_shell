class ParsingTest:
	test_count = 0

	def __init__(self, test_line):
		self.test_line = test_line
		self.expected = ''

		ParsingTest.test_count += 1
		self.test_count = ParsingTest.test_count


tests = [
	ParsingTest("ls"),
	ParsingTest("ls -l"),
	ParsingTest("ls -l -a"),
	ParsingTest("echo &"),
	ParsingTest("echo \'"),
	ParsingTest("echo \""),
	ParsingTest("echo \'\'"),
	ParsingTest("echo \"\""),
	ParsingTest("echo \"\'\""),
	ParsingTest("echo \'\"\'"),
	ParsingTest("echo \'&\'"),
	ParsingTest("ls | cat"),
	ParsingTest("ls -l | cat -e"),
	ParsingTest("ls -l | grep a | cat -e"),
	ParsingTest("echo 1 && echo 2"),
	ParsingTest("echo 1 && echo 2 && echo 3"),
	ParsingTest("ls -l | cat -e && echo deu bom"),
	ParsingTest("ls -l | cat -e && echo deu bom && echo eh isso"),
	ParsingTest("ls -l | cat -e && echo deu bom || echo deu ruim agora"),
	ParsingTest("ls -l | cat -e || echo deu ruim"),
	ParsingTest("< infile"),
	ParsingTest("< infile > outfile"),
	ParsingTest("< infile cat > outfile -e"),
	ParsingTest("/bin/cat < todo > out > out1 > out2 < todo"),
	ParsingTest("< infile cat > outfile -e && ls < infile > -a outfile -l"),
	ParsingTest("< infile cat | grep a > out"),
	ParsingTest("> out | /bin/ls"),
	ParsingTest("/bin/ls | < infile"),
	ParsingTest("/bin/ls | /bin/grep o > out | /bin/ps"),
	ParsingTest("/bin/ps > out | /bin/ls | /bin/grep o"),
	ParsingTest("< infile cat > outfile | < infile grep a"),
	ParsingTest("()"),
	ParsingTest("(ls)"),
	ParsingTest("(ls -l)"),
	ParsingTest("((ls -l))"),
	ParsingTest("((ls -l))"),
	ParsingTest("(ls) -l"),
	ParsingTest("(ls) -l -a"),
	ParsingTest("-l (ls)"),
	ParsingTest("< infile (/bin/cat > out -e > out2 | /bin/ps)"),
	ParsingTest("( /bin/ls < infile ) < infile | < infile /bin/cat -e && ( ( ( < infile /bin/cat -e ) ) )"),
	ParsingTest("< todo ( < todo /bin/ls < infile ) < infile | < infile /bin/cat -e && < infile ( < infile ( < infile ( < infile /bin/cat -e < todo ) < todo ) < todo ) < todo"),
	ParsingTest("(<infile())"),
	ParsingTest("<infile())"),
	ParsingTest("((/bin/ls)"),
	ParsingTest("(/bin/ls))"),
	ParsingTest("echo hi | cat -e > outfile1 && < infile1 | cat -e && < infile2 cat"),
	ParsingTest("echo hi | cat -e > outfile1 && < infile1 | cat -e && < infile2 cat"),
	ParsingTest("< infile1 cat"),
	ParsingTest("echo hi"),
	ParsingTest("echo hi | cat -e > outfile1 && < infile1 | cat -e"),
	ParsingTest("dsfasdf || echo hello | cat -e && echo bye || echo kitty"),
	ParsingTest("echo oi && ech oi2 | echo oi3 | echo oi4 || echo oi5"),
	ParsingTest("ech oi && echo hi | echo hello | echo bonjour || echo haha"),
	ParsingTest("echo oi || echo hi && echo hello && echo bonjour || echo haha"),
	ParsingTest("ech && echo oi || echo hey"),
	ParsingTest("ech oi || echo oi && echo hi | cat -e"),
	ParsingTest("echo hello | cat -e && ls | wc -l"),
	ParsingTest("echo hi > infile1 && echo bye > infile2"),
	ParsingTest("echo hi | cat -e > outfile1 && < infile1 | cat -e && < infile2 cat"),
	ParsingTest("< infile1 cat"),
	ParsingTest("< infile1 cat | echo"),
	ParsingTest("echo hi | cat -e > outfile1 && < infile1 | cat -e"),
	ParsingTest("cat outfile1"),
	ParsingTest("cat > ."),
	ParsingTest("cat > /"),
	ParsingTest("cat > usr/local/bin"),
	ParsingTest("cat > /usr/local/bin"),
	ParsingTest("cat > \"\""),
	ParsingTest("cat > \'\'"),
	ParsingTest("echo bye > \" \""),
	ParsingTest("cat < \" \""),
	ParsingTest("echo hi > \' \'"),
	ParsingTest("cat < \' \'"),
	ParsingTest("echo hello > \"fdasdfsa\""),
	ParsingTest("cat < \"fdasdfsa\""),
	ParsingTest("echo kitty > \"\"fdasdfsa\"\""),
	ParsingTest("cat < \"\"fdasdfsa\"\""),
	ParsingTest("cat < ."),
	ParsingTest("cat < /"),
	ParsingTest("cat < usr/local/bin"),
	ParsingTest("cat < /usr/local/bin"),
	ParsingTest("cat < \"\""),
	ParsingTest("cat < \'\'"),
	ParsingTest("cat < \" \""),
	ParsingTest("cat < \' \'"),
	ParsingTest("cat < \"fdasdfsa\""),
	ParsingTest("cat < \"\"fdasdfsa\"\""),
	ParsingTest("echo hi > ."),
	ParsingTest("echo hi > /"),
	ParsingTest("echo hi > usr/local/bin"),
	ParsingTest("echo hi > /usr/local/bin"),
	ParsingTest("echo hi > \"\""),
	ParsingTest("echo hi > \'\'"),
	ParsingTest("echo hi > \" \""),
	ParsingTest("cat < \" \""),
	ParsingTest("echo bye > \' \'"),
	ParsingTest("cat < \' \'"),
	ParsingTest("echo hi < ."),
	ParsingTest("echo hi < /"),
	ParsingTest("echo hi < usr/local/bin"),
	ParsingTest("echo hi < /usr/local/bin"),
	ParsingTest("echo hi < \"\""),
	ParsingTest("echo hi < \'\'"),
	ParsingTest("echo hi < \" \""),
	ParsingTest("echo hi < \' \'"),
	ParsingTest("export var=usr/local/bin var01=filename && cat > $var"),
	ParsingTest("export var01=filename && cat infile1 > \"\"$var01\"\""),
	ParsingTest("export var01=filename && cat \"\"$var01\"\""),
	ParsingTest("cat > \"\"$vor\"\""),
	ParsingTest("cat > $vor"),
	ParsingTest("echo $\"\" USER"),
	ParsingTest("echo $\"\" USER \"\""),
	ParsingTest("echo $\"\"\"                 \" USER \"\" hi"),
	ParsingTest("echo $\"\"\"\"\"\"\"\"\"\"\"\" USER \"\" hey"),
	ParsingTest("echo $\"\"\"\" USER \"\" a"),
	ParsingTest("echo $\"\"\'\' USER \"\" b"),
	ParsingTest("echo $\'\' USER \"\"c"),
	ParsingTest("echo $\'\'\'\' USER \"\"d"),
	ParsingTest("echo $\' \' \'\' USER \"\" e"),
	ParsingTest("echo $\' \'\"\" USER \"\" f"),
	ParsingTest("echo $\"\'\'\" USER \"\"g"),
	ParsingTest("echo $\'\'\'\' USER \"\" h"),
	ParsingTest("echo $  \"\'\'\" USER \"\" i"),
	ParsingTest("echo $  \"\"\"\" USER \"\" j"),
	ParsingTest("echo $  \"\" USER"),
	ParsingTest("echo \"        $USER   \" k"),
	ParsingTest("echo $"),
	ParsingTest("echo $$"),
	ParsingTest("echo $$$"),
	ParsingTest("$"),
	ParsingTest("$$"),
	ParsingTest("$$$"),
	ParsingTest("export carol=55 && echo $carol"),
	ParsingTest("export carol=55 && echo \"carol\""),
	ParsingTest("export carol=55 && echo $\"carol\""),
	ParsingTest("export carol=55 && echo \"$carol\""),
	ParsingTest("export carol=55 && echo \'$carol\'"),
	ParsingTest("export carol=55 && echo $carolbia$"),
	ParsingTest("export carol=55 && echo $carolbia$ hi"),
	ParsingTest("export carol=55 && echo $carol$?bia$ hi"),
	ParsingTest("export carol=55 && $\'carol\'$\'bia\'$ "),
	ParsingTest("export carol=55 && echo $\"carol\"$\"bia\"$"),
	ParsingTest("export carol=55 && $\'carol\'\'bia\'"),
	ParsingTest("export carol=55 && $\"carol\"\"bia\""),
	ParsingTest("export carol=55 && echo $carolbia$ | cat -e > outfile3 && echo bye"),
	ParsingTest("export carol=55 var=\"o hello\" var50=\"abc      def\" && ech$var"),
	ParsingTest("export carol=55 var=\"o hello\" var50=\"abc      def\" && echo $var50"),
	ParsingTest("echo $adfasfsd"),
	ParsingTest("$adfasfsd"),
	ParsingTest("$%342342"),
	ParsingTest("$\"342342"),
	ParsingTest("export \"\""),
	ParsingTest("export var30 && export | grep var30"),
	ParsingTest("export var30 && export var30=carol && export | grep var30"),
	ParsingTest("export var20=bia && export | grep var20"),
	ParsingTest("export var20=bia && export var20 && export | grep var20"),
	ParsingTest("export var=variable && export $var=carol && export | grep $var"),
	ParsingTest("export var40=oi var50=hi && export var= && export | grep var=\"\""),
	ParsingTest("export var= && export var=20 && export | grep var="),
	ParsingTest("export var=20 && export var= && export | grep var="),
	ParsingTest("export var70 && export | grep var70"),
	ParsingTest("export var10 && export var100 && export | grep var10"),
	ParsingTest("export \" \""),
	ParsingTest("export \'\'"),
	ParsingTest("export \' \'"),
	ParsingTest("export var=variable && export $var=$USER && export | grep variable="),
	ParsingTest("export var=oi | echo hey"),
	ParsingTest("unset \"\""),
	ParsingTest("export var=variable && export $var=123"),
	ParsingTest("export var20=carol && export | grep var20"),
	ParsingTest("export var30 && export | grep var30"),
	ParsingTest("export var40= && export | grep var40"),
	ParsingTest("export carol=55 && $USER$carol"),
	ParsingTest("export carol=55 && export var=variable && $USER$var"),
	ParsingTest("oitudobem"),
	ParsingTest("$USERoi"),
	ParsingTest("$USER\'"),
	ParsingTest("\"$USER\""),
	ParsingTest("\'$USER\'"),
	ParsingTest("\"$USER\'"),
	ParsingTest("$"),
	ParsingTest("$$"),
	ParsingTest("$$$"),
	ParsingTest("echo oi > tudo bem"),
	ParsingTest("cat tudo"),
	ParsingTest("< infile1 cat | echo hey"),
	ParsingTest("echo hey | < infile1 cat"),
	ParsingTest("whoami | < infile1 cat"),
	ParsingTest("rm infile1"),
	ParsingTest("echo hey | < infile1 cat"),
	ParsingTest("whoami | < infile1 cat"),
	ParsingTest("echo hi | (echo hello | cat -e)"),
	ParsingTest("echo hi | (echo hello && echo bye) | cat -e"),
	ParsingTest("(export var=carol) && export | grep var="),
	ParsingTest("(ech hi || echo carol > outfile1 && echo bia) | cat -e && echo bye"),
	ParsingTest("(ech hi || (echo carol > outfile1 && echo bia)) | cat -e && echo bye"),
	ParsingTest("(ech hi || (echo carol > outfile1  | echo bia)) | cat -e && echo bye"),
	ParsingTest("(echo bye) echo hi ) (ls (echo hi)"),
	ParsingTest("(echo bye)) ((echo hi)"),
	ParsingTest("((echo hi | cat -e) | cat -e)"),
	ParsingTest("echo \"(hello)\" > infile1"),
	ParsingTest("cat infile1 | grep \");\"$"),
	ParsingTest("cat infile1 | grep \"(\""),
]