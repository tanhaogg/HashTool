//
//  AppDelegate.m
//  DragHash
//
//  Created by Hao Tan on 12-3-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
}

- (void)awakeFromNib
{
    [self.window setReleasedWhenClosed:NO];
}

- (BOOL)applicationShouldHandleReopen:(NSApplication *)theApplication hasVisibleWindows:(BOOL)flag
{	
	if (!flag) 
    {
		[_window makeKeyAndOrderFront:self];
	}
	return YES;
}

- (void)dragFileEnter:(NSString *)aFilePath
{
    filePath = [aFilePath copy];
    NSString *fileName = [filePath lastPathComponent];
    [titleField setStringValue:fileName];
    [self kindClick:nil];
}

- (IBAction)kindClick:(id)sender
{
    if (!filePath || ![[NSFileManager defaultManager] fileExistsAtPath:filePath]) 
    {
        [titleField setStringValue:@"把文件拖到这里"];
        [hashField setStringValue:@""];
        return;
    }
    
    THHashKind kind;
    switch ([kindButton indexOfSelectedItem])
    {
        case 0: kind = THHashKindMd5;break;
        case 1: kind = THHashKindSha1;break;
        case 2: kind = THHashKindSha256;break;
        case 3: kind = THHashKindSha512;break;
        default:kind = THHashKindMd5;break;
    }
    NSString *hash = [THWebUtility hashFile:filePath with:kind];
    if (hash)
    {
        [hashField setStringValue:hash];
    }
}

- (IBAction)copyClick:(id)sender
{
    if ([[hashField stringValue] length] > 0)
    {
        NSPasteboard *pasteBoard = [NSPasteboard generalPasteboard];
        [pasteBoard clearContents];
        [pasteBoard setString:[hashField stringValue] forType:NSPasteboardTypeString];
    }
}

- (IBAction)aboutClick:(id)sender
{
    [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:@"http://www.tanhao.me"]];
}

@end
