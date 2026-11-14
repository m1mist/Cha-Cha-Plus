<p align="center">
  <img src="docs/images/cha-cha.png" width="128" alt="Cha-Cha">
</p>

<h1 align="center">Cha-Cha (日版 v96 分支)</h1>

<p align="center">
  <b>《怪物猎人 3G HD Ver.》（日版 v96）PC 原生静态重编译版。</b><br>
  将 Wii U 游戏静态重编译至 Windows 与 Linux 原生运行，基于 <a href="https://github.com/SilversRayGA/Cha-Cha-Plus">SilversRayGA/Cha-Cha-Plus</a> 移植。
</p>

<p align="center">
  <a href="../../releases/latest"><img src="https://img.shields.io/github/v/release/m1mist/Cha-Cha-Plus?label=release&color=ecb254" alt="Latest release"></a>
  <img src="https://img.shields.io/badge/platform-Windows%20%7C%20Linux-3b332a" alt="Windows and Linux">
  <img src="https://img.shields.io/badge/graphics-Vulkan-3b332a" alt="Vulkan">
  <a href="LICENSE"><img src="https://img.shields.io/badge/license-GPL--3.0-3b332a" alt="GPL-3.0"></a>
</p>

<p align="center">
  <a href="README.md">English</a> · <b>简体中文</b>
</p>

<p align="center">
  <a href="#安装说明">安装</a> ·
  <a href="#快速开始">快速开始</a> ·
  <a href="#相比原版的新增特性">新增特性</a> ·
  <a href="#dlc活动与挑战任务">DLC 任务</a> ·
  <a href="#模组mods">模组</a> ·
  <a href="#材质包与材质导出">材质包</a> ·
  <a href="#联机游玩实验性">联机</a> ·
  <a href="#后续规划">后续规划</a> ·
  <a href="#从源码构建">从源码构建</a>
</p>

---

Cha-Cha 会把游戏的 PowerPC 代码提前翻译为 C++ 并编译为 PC 原生程序。它运行在我们自行重新实现的 Wii U 系统库之上，图形基于 Vulkan，输入与音频基于 SDL3。**它不是模拟器，项目中不包含任何模拟器代码。**

> [!IMPORTANT]
> **本仓库不包含任何游戏文件。** 你需要自行准备 **《怪物猎人 3G HD Ver.》（日版）含 v96 更新** 的游戏副本（Title ID `0005000010104D00`，`MH3G_Cafe.rpx`）。
> 如需美版 v32，请访问上游仓库 [SilversRayGA/Cha-Cha-Plus](https://github.com/SilversRayGA/Cha-Cha-Plus)。
> Cha-Cha 是一个爱好者开源项目，与 Capcom 或任天堂没有任何隶属或背书关系。

## 安装说明

你需要自备 **《怪物猎人 3G HD Ver.》（日版）v96 更新** 的游戏镜像（`.wua` 文件，或解包后的游戏与更新目录）。

**Windows**
1. 从 [Releases](../../releases/latest) 下载 `Cha-Cha-<version>-windows-x64.zip`。
2. 解压到有写入权限的目录（不要放在 Program Files）。
3. 运行 `Cha-Cha.exe`，在初始设置界面选择你的游戏目录或 `.wua` 文件。

**Linux / Steam Deck**
1. 从 [Releases](../../releases/latest) 下载 `Cha-Cha-<version>-x86_64.AppImage`。
2. 赋予可执行权限：`chmod +x Cha-Cha-*.AppImage`（或在文件属性中勾选“允许作为程序运行”）。
3. 运行程序并在初始设置界面选择你的游戏文件。

首次启动会将游戏的着色器翻译为 PC 可用格式（耗时数秒，仅一次），随后自动进入游戏。按 **F1** 或手柄 **Select + Options** 可打开设置界面，左侧分页依次为 Display、Graphics、Controls、Gameplay、**Mods**、**Quests** 与 System（可用 LB / RB 或 Q / E 切换分页），退出游戏在 System 页中；按 **F2** 可直接打开 Mods 页面。菜单界面使用你本地游戏资源中的贴图绘制，发布包内不附带任何游戏贴图。程序内置 **Damage Numbers（伤害数字）** 模组，可在 Mods 页开关。

**添加模组：** 将每个模组文件夹放入数据目录下的 `mods` 文件夹中（Windows 为 `Cha-Cha.exe` 同级的 `data\mods`，Linux 为 `~/.local/share/Cha-Cha/mods`），重启 Cha-Cha 即可生效。

## 相比原版的新增特性

以下改动已直接集成到游戏中，其中“怪物血量缩放”可在 Settings → General 中关闭。

<table>
  <tr>
    <td width="33%" valign="top">
      <h3>道具套装（Item Sets）</h3>
      类似《怪物猎人 XX / GU》的快捷配装/道具套装功能，直接集成在游戏道具箱菜单中（包括家里道具箱以及坦齐亚港码头的小道具箱）。
      <ul>
        <li><b>登录道具套装</b> 保存当前随身背包，<b>读取道具套装</b> 自动补满背包。</li>
        <li>剑士与弩手各提供 5 个套装槽位。</li>
        <li>读取时按实际拥有数量补充，并提示缺少的道具。</li>
        <li>选择时右侧背包预览窗口会实时预览结果，左右键可翻页。</li>
      </ul>
    </td>
    <td width="33%" valign="top">
      <h3>怪物血量动态缩放</h3>
      坦齐亚港的任务默认按 4 人联机平衡。当人数少于 4 人时，怪物血量会按人数缩放：
      <table>
        <tr><th>猎人数</th><th>血量比例</th></tr>
        <tr><td>1</td><td>65%</td></tr>
        <tr><td>2</td><td>80%</td></tr>
        <tr><td>3</td><td>90%</td></tr>
        <tr><td>4</td><td>100%</td></tr>
      </table>
      覆盖下位、上位与 G 级全部任务；莫加村任务保持原版不变。可在 Settings → General → <b>Monster HP scaling</b> 中关闭以恢复原版血量。
    </td>
    <td width="33%" valign="top">
      <h3>长按连续采集/剥取</h3>
      在怪物尸体、采集点或矿点长按采集键即可持续采集/剥取直至耗尽，无需反复连按。
      <h3>DLC 任务重现</h3>
      原服务器停服后无法下载的活动与挑战任务，现在可通过本地文件重新安装。
      <a href="#dlc活动与挑战任务">详见下文。</a>
    </td>
  </tr>
</table>

### 为 PC 体验打造的改进

- **自定义分辨率与帧率：** 内部分辨率支持 0.5× 到 4×（最高 5120×2880），支持帧率上限调节（直至不限帧率）、垂直同步、窗口/无边框/全屏模式，以及平滑或锐利画面缩放。
- **Wii《怪物猎人 3》风格色调（Tri look）：** 仅对游戏世界场景应用更柔和朦胧的复古画面风格（菜单与 HUD 保持原样）。
- **原版所没有的画面增强：** 可选全局光照（GI）、环境光遮蔽（AO）、增强景深与暗角效果；原版自带的泛光（Bloom）与景深也可单独关闭。
- **材质包支持** 以及用于制作材质包的材质导出功能。
- **跳过过场动画：** 按 **+**（Start / Options，或键盘绑定到 `+` 的按键）即可跳过过场动画。
- **直入游戏：** 默认跳过启动器菜单直接进入游戏（加 `--menu` 参数可显示启动器）。游戏内按 **F1** / **Select + Options**（或 PlayStation 触摸板 / Home 键）呼出悬浮设置（General 页含 Quit game），**F2** 打开模组页，**F3** 切换 GamePad 副屏显示方式（隐藏 / 画中画 / 仅副屏），**F11** 切换全屏与窗口并释放鼠标。
- **灵活的键鼠与手柄控制：** 支持键鼠以及 SDL 支持的各类手柄（映射为 Wii U Pro 手柄）。所有按键均可重映射，设置界面支持按你的按键绑定显示 Xbox、PlayStation 或 Nintendo 按键图标名称。
- **鼠标点选菜单：** 在游戏菜单中支持鼠标直接指向与点击选择——涵盖开始/暂停菜单、道具箱、商店、工匠、任务柜台、猫饭、小屋、农场、船夫、补给箱及各类确认弹窗。
- **PC 键盘输入：** 角色命名与聊天直接调用 PC 键盘输入，替代 Wii U 软键盘。

## 快速开始

| | Windows | Linux |
|---|---|---|
| **下载** | 从 [Releases](../../releases/latest) 下载 `Cha-Cha-<version>-windows-x64.zip` | 从 [Releases](../../releases/latest) 下载 `Cha-Cha-<version>-x86_64.AppImage` 或压缩包 `Cha-Cha-<version>-linux-x86_64.tar.gz` |
| **系统要求** | Windows 10 / 11 x64 | x86-64 且 glibc ≥ 2.35（Ubuntu 22.04、Fedora 36、Steam Deck 等） |
| **显卡要求** | 支持 Vulkan 1.2 的驱动 | 支持 Vulkan 1.2 的驱动（Mesa 或显卡厂商闭源驱动） |
| **运行方式** | 解压到可写目录并运行 `Cha-Cha.exe` | 执行 `chmod +x Cha-Cha-*.AppImage` 后运行；或解压文件夹版本运行 `./Cha-Cha` |

1. **启动 Cha-Cha。** 首次启动时引导界面会要求选择游戏文件。
2. **指定你的游戏镜像：** 选择 `.wua` 归档文件，或已解包的游戏目录（含 `code`、`content`、`meta`）。Cha-Cha 会校验其是否为日版 v96 可执行文件（`0005000010104D00` / `MH3G_Cafe.rpx`）并直接就地读取，不会复制整份游戏文件。
3. **等待几秒：** 首次运行时程序会为你的 PC 预编译游戏着色器，仅需一次。

你的**数据目录**用于存放设置、存档、着色器缓存、DLC 任务与材质包：

| | 数据目录路径 |
|---|---|
| Windows | `%APPDATA%\Cha-Cha` |
| Linux | `~/.local/share/Cha-Cha`（或 `$XDG_DATA_HOME/Cha-Cha`） |
| 便携模式（Portable） | 当程序同级目录存在 `portable.txt` 文件时，使用同级的 `data/`（Windows 压缩包默认启用） |
| 目录模式（Folder） | 当程序同级目录存在 `Cha-Cha.ini` 时，直接以程序所在目录作为数据目录（Linux 文件夹发布版默认启用） |

存档位于 `<数据目录>/save`。如需跳过首次引导界面，可通过 `--install <游戏路径>` 参数启动。

### 文件夹版目录结构

与常见的静态重编译项目类似，所有内容都在同一目录下，解压到任意可写路径即可：

```
Cha-Cha-<version>/
├── Cha-Cha                 主程序
├── Cha-Cha.ini             配置文件（使当前目录作为数据目录）
├── game/                   你的游戏副本：游戏/更新目录或 .wua 文件（自动识别）
├── mods/                   模组目录，每个模组一个子文件夹（内置 Damage Numbers、True Attack、Key Quests、Charm Table Fix）
│   └── damage-numbers/
├── licenses/               Cha-Cha 的 GPL-3.0 协议及第三方库许可
├── README.txt
│   首次运行后自动生成：
├── cache/                  翻译后的着色器与管线缓存
├── save/                   游戏存档
├── quests/                 活动与挑战任务
├── texture_replacements/   替换材质包
└── log.txt                 运行日志（非终端启动时生成）
```

Linux 文件夹版本依赖系统发行版提供的 FFmpeg `libavcodec`（用于视频播放）；如果目标发行版与编译环境不一致，建议直接使用 AppImage。

### 默认按键映射

| Wii U Pro 手柄 | 键盘与鼠标 | 手柄 |
|---|---|---|
| 左摇杆 / 右摇杆 | WASD / O K L ;（或鼠标：点击窗口捕获，Esc 释放） | 左/右摇杆 |
| A / B / X / Y | F、回车或右键 / 空格或退格 / 左键 / E | 按 Wii U 物理键位对应 |
| 同时按 X + A | 鼠标侧键 4 | |
| L / R / ZL / ZR | Q 或左 Ctrl / 左 Shift 或鼠标侧键 5 / Z / C | LB / RB / LT / RT |
| + / − | Tab / M | Back / Start |
| 十字键（D-pad） | 方向键、鼠标滚轮 | 十字键 |

在 Settings → Input 中可将手柄切换为 Xbox 布局（A / × 确认）并自由改键。**Camera speed（视角速度）** 可将摇杆、键盘与鼠标转动视角的速度调节为原版的 30%～100%。键位与设置保存在 `<数据目录>/input.ini`（详见 [docs/input.md](docs/input.md)）。

## DLC：活动与挑战任务

Capcom 当年的配信任务下载服务器已关闭，Cha-Cha 支持通过本地文件直接安装活动与挑战任务：

1. 在启动器或菜单中打开 **MODS → Quests → Quest folder**，对应目录为 `<数据目录>/quests`。
2. 将任务文件放入该目录（建议按任务包建立子目录）：
   - **官方 DLC：** 从带有已下载任务的 Wii U 存档中提取 `quest1`、`quest2`、`quest3` 和 `quest4` 四个文件（例如放到 `quests/DLC/`），官方存档包会自动整包识别。
   - **自定义/散装任务：** 放入 `q_<编号>.quest` 文件，可选配 `pack.json`、`cover.png` 以及每个任务对应的图片与简介文件，支持在界面中逐个勾选安装。
3. 安装后的任务会出现在**坦齐亚港集会所**的活动任务与挑战任务列表中。

任务包格式详见 [docs/mods.md](docs/mods.md)。任务文件属于游戏数据，因此本仓库不附带任何任务文件。

## 模组（Mods）

将模组放入 `<数据目录>/mods`（每个模组一个独立文件夹）。在 **MODS → Mods**（游戏内按 F2）可查看列表、开关模组（下次启动生效）以及调整模组设置。

- **内容模组（Content mods）：** 包含 `content/` 目录，按与游戏 `content` 相同的相对路径覆盖或追加资源文件，不会修改原始镜像。
- **原生插件（Plugins）：** Windows 为 `plugins/*.dll`，Linux 为 `plugins/*.so`，可直接 Hook 游戏函数、在画面上绘制覆盖层并向菜单注册设置项。插件 API 定义在单个 C 头文件 [`include/chacha_plugin.h`](include/chacha_plugin.h) 中。

内置模组：
- **Damage Numbers**（[mods/damage-numbers](mods/damage-numbers/README.md)）：在怪物身上显示每次攻击的伤害数字，支持 Wilds、Rise 与 Classic 三种风格。
- **True Attack**（[mods/true-attack](mods/true-attack/README.md)，可选，默认关闭）：在菜单中显示武器真实攻击力而非面板虚高倍率（如铁锤显示 70 而非 364），不改变实际伤害。
- **Key Quests**（[mods/key-quests](mods/key-quests/README.md)，可选，默认关闭）：在任务柜台列表中为推进紧急任务所需的关键任务标注金色钥匙图标、“2 OF 5”进度及 URGENT 标记。
- **Charm Table Fix**（[mods/charm-table-fix](mods/charm-table-fix/README.md)，可选，默认关闭）：解除护石表锁死问题，让任意存档都有机会获得全部护石，同时保留原有存档的表编号。

模组制作指南见 [docs/modding.md](docs/modding.md)。

## 材质包与材质导出

**使用材质包：** 将 `.dds` 材质文件放入 `<数据目录>/texture_replacements`（支持子目录），并在 Settings → Video 中开启 **Texture packs**（游戏中可随时实时开关）。

**制作材质包：**

1. 开启 Settings → Video → **Dump textures**。此后游戏绘制的每张材质都会以替换所需的命名格式 `tex_<宽>x<高>_<CRC32>.dds` 保存至 `<数据目录>/texture_dump`（屏幕角落会提示路径与导出数量，持续到退出游戏）。
2. 编辑你需要替换的贴图，保留原文件名前缀（可在 CRC 后追加备注文本）并生成 mipmap，再复制进 `texture_replacements` 即可。

请注意，3DS 版的材质包与 Wii U 版贴图不匹配，无法通用。详情见 [docs/texture-packs.md](docs/texture-packs.md)。

## 联机游玩（实验性）

> [!WARNING]
> **联机功能处于早期实验阶段。** 当前几乎未经大规模实机测试，可能出现异常、断线或不同步。测试前请务必备份你的 `save` 文件夹！

**遇到问题欢迎提交 [Issue](../../issues)**，反馈时请尽量附上：
- Cha-Cha 版本与操作系统
- 是单机双开还是多台电脑，谁是房主
- 操作步骤、实际现象与预期表现
- 如方便请附上**每一端**数据目录中的 `log.txt`

### 工作原理

任天堂官方服务器已经停服，Cha-Cha 也不依赖任何中央服务器。项目保留了游戏自身的联机逻辑，仅替换掉原本与任天堂服务器通信的底层接口。由一名玩家担任房主，其余玩家之间直接通过 UDP（端口 47800–47807）点对点交换数据，房主接取任务后其他成员跟随出发。

默认关闭网络联机（此时仅允许同一台电脑上的多开实例互相连接）。联机数据未加密且会直接传入游戏内存，请仅在信任的朋友和网络环境中开启网络联机。

### 联机步骤

所有玩家都需要使用相同版本的 Cha-Cha、自备游戏副本，并拥有已经到达坦齐亚港的存档。

1. **所有玩家：** 在 Settings (F1) → Gameplay → Online 中开启 **Play over the network** 并点击 Apply（若弹出防火墙提示请放行）。
2. **房主：** 在坦齐亚港与猫船长对话，在联机选项中选择 **Host a Hunt**，等待出现“Hosting a hunt”。
3. **其他玩家：** 与猫船长对话选择 **Join a Hunt**（若首次进入坦齐亚港触发过场运镜，加入耗时可能会多出约 30 秒）。
4. **房主：** 在集会所柜台接取任务并出发，其余成员随后加入。
5. **退出联机：** 通过猫船长选择 **Leave Online**，或在设置中选择离开会话。

如果在局域网中搜索不到房主，可在数据目录的配置文件（`config.ini` 或 Linux 文件夹版的 `Cha-Cha.ini`）中加入 `online_host=<房主实际IPv4地址>`，然后重启游戏。

**单机本地多开测试：** 复制一份 `save` 文件夹到新目录，使用 `Cha-Cha --data-dir <新目录>` 启动第二个客户端并选择同一份游戏镜像，两端保持关闭网络联机即可（手柄输入会同时作用于两个窗口，因此建议一个窗口使用手柄、另一个窗口使用键盘）。

### 当前测试进展

| 测试项 | 状态 |
|---|---|
| 建房与加入 | 已在 Linux 单机双开中实机验证 |
| 双人同驻集会所、退出重连、共同接任务、大型怪物同步移动、同步伤害 | 仅通过自动化测试 |
| 完整任务柜台出发、剥取、结算奖励、聊天与完整狩猎流程 | **尚未实机验证** |
| 跨电脑、3～4 人联机、Windows 版本联机、公网联机 | **尚未实机验证** |

更多细节见 [docs/online.md](docs/online.md)。

## 后续规划

- **联机完善：** 稳定现有的[实验性联机功能](#联机游玩实验性)，后续增加跨公网房间发现机制，并按真实联机猎人数触发怪物血量缩放。
- **内置任务编辑器（Quest maker）：** 支持在游戏内自制任务并生成分享码，复制发送即可让其他人导入游玩。

## 从源码构建

构建过程会把**你自己的游戏可执行文件**静态重编译为 C++，因此编译前必须先准备好游戏解包文件。

1. 将日版 v96 的 `.wua` 镜像放入 `game/` 目录（例如 `game/mh3g.wua`，参考 [game/README.md](game/README.md)），然后依次运行：
   `powershell -File scripts/extract.ps1` 与 `powershell -File scripts/fingerprint.ps1`。  
   [config/target.txt](config/target.txt) 对应的目标校验为 `0005000010104d00_v96`（`MH3G_Cafe.rpx`，SHA-1 `cb908d6807891f4edb5b00fdf2a1d5688ee0b935`）。
2. **Windows：** 需安装 Visual Studio 2026（含“使用 C++ 的桌面开发”）以及 Vulkan SDK（详见 [tools/README.md](tools/README.md)）：

   ```powershell
   cmake -S . -B build/cmake
   cmake --build build/cmake --config Release
   ctest --test-dir build/cmake -C Release --output-on-failure
   ```

   使用 `clang-cl` 工具链（`cmake -S . -B build/clang -T ClangCL`）通常可以更快编译生成的重编译 C++ 代码。  
   运行 `scripts/package-release.ps1` 可打包发布用 zip。
3. **Linux**（或 Windows WSL2）：需 clang 15+、Ninja、CMake 3.25+、LunarG Vulkan SDK、`libvulkan-dev`、`libavcodec-dev` 与 SDL3 构建依赖。可用 `scripts/build-linux.sh` 构建，`scripts/package-appimage.sh` 制作 AppImage（详见 [docs/linux.md](docs/linux.md)）。

   如果希望在 Linux 桌面环境使用系统自带的 SDL3（例如 Fedora 需安装 `SDL3-devel`、`libshaderc-devel`、`vulkan-loader-devel`、`libavcodec-free-devel`），可加上 `-DMH3U_SYSTEM_SDL3=ON`（注意若自行从源码构建 SDL3 但缺少 PipeWire / PulseAudio / ALSA 开发头文件，游戏将没有声音）：

   ```bash
   cmake -S . -B ~/cha-cha-build -G Ninja -DCMAKE_BUILD_TYPE=Release -DMH3U_SYSTEM_SDL3=ON \
         -DMH3U_RECOMP_OUT=$HOME/cha-cha-build/recomp-out
   cmake --build ~/cha-cha-build --target mh3u damage_numbers
   scripts/package-folder.sh ~/cha-cha-build <version>      # 文件夹发布包输出在 build/release/
   ```

在源码目录中直接运行时，Cha-Cha 会自动识别 `extracted/` 并以源码目录作为数据目录（相关产物均已在 `.gitignore` 中排除）。打包出的发布版绝不包含游戏资源文件，但可执行程序本体中包含了在构建时从你的游戏镜像翻译出的重编译代码。

<details>
<summary><b>仓库目录说明</b></summary>

| 路径 | 用途 | 是否纳入 Git |
|---|---|---|
| `game/`, `extracted/` | 游戏镜像与解包后的内容 | 否 |
| `config/` | 目标哈希、符号表、函数表与已知数据结构定义 | 是 |
| `recomp/` | 静态重编译器源码；`recomp/out/` 为生成的 C++ | 仅源码 |
| `runtime/` | 替代 Wii U 系统的 PC 运行时：`os`、`gfx`（Vulkan 实现 GX2）、`audio`、`input`、`fs`、`boot` | 是 |
| `src/` | 手写游戏功能代码：道具套装、长按采集、血量缩放等 | 是 |
| `include/` | `chacha_plugin.h`，模组插件开发头文件 | 是 |
| `mods/` | 随树构建的内置模组（Damage Numbers、True Attack 等） | 是 |
| `tools/`, `scripts/`, `ghidra/` | 着色器转换器、辅助脚本与逆向工程脚本 | 是 |
| `docs/` | 开发路线图、逆向日志、格式文档、模组/输入/Linux/联机说明 | 是 |
| `build/` | 构建输出目录 | 否 |

项目工作原理与逆向记录可参阅 [docs/runtime.md](docs/runtime.md)、[docs/engine.md](docs/engine.md)、[docs/research-log.md](docs/research-log.md)。

</details>

## 致谢

- **Dusklight**：《塞尔达传说：黄昏公主》PC 移植版，Cha-Cha 的前端界面（启动器、标题画面、设置窗口）沿用了其设计风格。
- **Yakumo**：Cha-Cha 遵循了其“零资源分发”发布模型：只发布重编译程序，玩家自行提供本地游戏副本。
- **Ghidra**：逆向工程分析工具。
- **第三方库：** SDL3、Dear ImGui、zstd、Vulkan SDK（shaderc、glslang、SPIRV-Tools），以及 Linux 下的 FFmpeg libavcodec（见 [docs/release/THIRD_PARTY_NOTICES.md](docs/release/THIRD_PARTY_NOTICES.md)）。

Monster Hunter 为 Capcom 注册商标；Wii U 为任天堂注册商标。

## 开源协议

Cha-Cha 是基于 **GNU General Public License v3.0**（[LICENSE](LICENSE)）协议的自由软件：你可以自由使用、研究、修改并分发本软件；如果你分发修改后的版本，也必须以相同协议开源其源码。第三方库各自保留其原有协议。本协议仅适用于 Cha-Cha 自身的代码，不涵盖原游戏本身：《怪物猎人 3G HD Ver.》/《怪物猎人 3 Ultimate》及其衍生内容版权仍归 Capcom 所有。
