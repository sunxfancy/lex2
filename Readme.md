Lex2
==========


Based on the project lex, it has some improvements for definition structure
and initial state feature.


### New version definition structure

More like flex, there is a 'regex' definition part.

```
#DEFINE

nl			(\r\n|\r|\n)
ws			[ \t\r\n]+
open			{nl}?"<"
close			">"{nl}?
```

using `#DEFINE` to define those regex lines. It can be used recursively.


There are also some changes for support initial state feature:

```
#CONTENT

init {
	skip: {ws}
	version: {version}
	encoding: {encoding}
	opt: [/=]
	close: {close}			goto content
	name: {name}
	string: {string}
	def-end: "?"{close}
}

init, content {
	def-att: {attdef}
	start: {open}{ws}?{name} 	goto init
	end: {open}{ws}?"/"		goto init
	comment: {comment}
}

content {
	data: {data}
}

{
	error: .
}

```


The name before `{}` means those patterns are belong to those kinds of states.
`init` is the begin state for the lexer.

With `goto` command, the lexer state can be changed from `init` to others.