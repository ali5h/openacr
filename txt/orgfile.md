## Orgfile: organize and deduplicate files by timestamp and by contents

### Syntax

```
inline-command: orgfile -h


orgfile: OpenACR File deduplicator tool
Usage: orgfile [options]
    -in       string  Input directory or filename, - for stdin. default: "data"
    -move     string  Read stdin, rename files based on pattern
    -dedup    string  Only allow deleting files that match this regx
    -commit           Apply changes. default: false
    -undo             Read previous orgfile output, undoing movement. default: false
    -hash     string  Hash command to use for deduplication. default: "sha1"
    -verbose          Enable verbose mode
    -debug            Enable debug mode
    -version          Show version information
    -sig              Print SHA1 signatures for dispatches
    -help             Print this screen and exit

```

### Description

Orgfile reads a list of filenames from stdin and performs move and dedup operations with
incoming files. 
This tool is based on openacr and can be merged into any clone of openacr, or compiled stand-alone
with `make`.

If `-commit` is specified, the operation is performed. Otherwise, the description of intended
operation is printed to stdout and no action occurs.

If `-move` is specified, then each incoming file is moved to directory specified by `-move`, if that
argument ends with a /. Otherwise, the file is renamed.

If the target file exists and has the same checksum, as determined by the checksum algorithm, the source file is deleted.
If the target file exists, a suffix "-2", "-3", etc is appended 
to the incoming file's basename (so, `a.txt` becomes `a-2.txt`).

When moving, orgfile treats the target filename as an expression, where the following substitutions occur.
First, $basename, $filename, $ext are replaced with corresponding path components of the original file.
Second, orgfile determines a date associated with the file and replaces %Y, %b, %m and %d in the target pathname
with the discovered date.

The date is discovered using the following algorithm:
- First, the parent directory of the file is checked for any pattern specified in table `dev.timefmt` marked `dirname:Y`.
(For instance, `"%Y-%m-%d"`)
- If this doesn't yield a timestamp, then the filename is checked for any pattern from `timefmt` table marked `dirname:N`.
Any number of patterns can be provided in the table. Default timefmts support photoshop image name formats.
- If this doesn't yield a timestamp, then the file modification time is used.
Note, use of formatting specifiers other than `%Y,%m,%b,%d` for `-subdir` may
yield zeros.

The parameter `-hash` specifies the command to use to compute file hashes. It is `sha1` by default, but can
be the name of any command. The output of the command is filtered (removing spaces and everyhing before `=` sign),
and the rest is taken to the a file checksum for the purposes of determining duplicates (this works both
with `-move` and with `-dedup`)

If `-dedup` is specified, then any incoming file is scanned for its hash.
Any file whose pathname matches the pattern specified by `-dedup`, and the file is proven to be a duplicate,
is deleted.

### Reading Output As Input

Orgfile can accept its own output as input. This is useful for inserting filters such as grep.
Aside from filenames, orgfile input can contain tuples that start with orgfile.move and orgfile.dedup.
For orgfile.move, orgfile either performs the raw filesystem move (with no evaluation or deduplication), or, with 
`-undo`, moves the target file back to the source file.
For orgfilededup, orgfile deletes the duplicate file. With `-undo -dedup`, orgfile does nothing
since deletion cannot be undone.
For some move operations, `-undo` will move files back to their original locations.

## Examples

### Find files with identical contents (but don't do anything with them)
```
find . | orgfile -dedup
```

### Same as above but with an additional filter
```
find . | orgfile -dedup | grep <blah> | orgfile -commit
```

### Delete files in secondary backup that already exist in primary backup
```
find backup backup2 -type f | orgfile -dedup:"backup2/%" -commit
```

### Organize images by year and day
```
find . -name "*.jpg" | orgfile -move:image/%Y/%Y-%m-%d/ -commit
```
