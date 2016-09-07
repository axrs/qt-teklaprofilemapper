# Qt Tekla Profile Mapper

Tekla Structures (TS) has a large database of member or component profiles. Unfortunately the default `PROFILE_NAME` doesn't align with our company standards.
TS has the ability to extend the default database by adding new fields to each profile through User Defined Attributes (UDA).

Instead of manually processing the `PROFILE_NAME`s into a desired `DISPLAY_NAME` (UDA we added), this small application:

1. Reads an exported `profiles.lis` database dump (which is a plain text file for all essential purposes).
2. Extracts the `PROFILE_NAME` attribute and with a bit of manipulation, saves it as a `DISPLAY_NAME` attribute.
3. Writes a new `mapped_profiles.lis` file to disk.

## Usage
1. Add a `DISPLAY_NAME` UDA to the profile catalogue and export the entire database.
2. Build and compile this project.
3. Drag and drop the exported `profiles.lis` file onto the executable (`TeklaProfileMapper.exe`).
4. Import the new `mapped_profiles.lis` back into Tekla Structures and change manage the conflicts via the UI.

## Notes:
- Only tested on Windows 7.
- Only tested with `PROFILE DATABASE EXPORT VERSION = 3`. Other versions should work however.


### Example Profile Exported from Tekla
#### Before Mapping
```
PROFILE_NAME = "UB150*14";
{
    TYPE = 1; SUB_TYPE = 1001; COORDINATE = 0.000;
    {
        ...<snip>...
        "DISPLAY_NAME"                      ""
    }
}
```

#### After Mapping

```
PROFILE_NAME = "UB150*14";
{
    TYPE = 1; SUB_TYPE = 1001; COORDINATE = 0.000;
    {
        ...<snip>...
        "DISPLAY_NAME"                      "150UB14"
    }
}
```
