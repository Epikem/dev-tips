# for mac, zsh
echo 'setopt interactivecomments' >> ~/.zshrc && source ~/.zshrc

# install brew, the script maybe interactive (need password and confirm) so need mDLp1i3o2i395^epi2
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# - Run these two commands in your terminal to add Homebrew to your PATH:
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /Users/hyunwoolee/.zprofile
eval "$(/opt/homebrew/bin/brew shellenv)"

# dev tools
brew install hyper
brew install wget
brew install pyenv
brew install go-task/tap/go-task
brew install graphviz
brew install asciinema
brew install gpg
brew install tree
brew install java
brew install visual-studio-code
brew install warp

# productivity tools
brew install rectangle
brew install firefox
brew install app-cleaner
brew install zoom
brew install obsidian
brew install dropbox
brew install karabiner-elements
# brew install anaconda

# install oh-my-zsh
# cannot install oh-my-zsh with brew
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"

brew install macs-fan-control
brew install scroll-reverser
brew install gpg2
brew install git-secret
brew install shellcheck

brew install podman
brew install podman-compose
brew install podman-desktop
brew install fnm # or use setup script: curl -fsSL https://fnm.vercel.app/install | bash  (dependencies: curl, unzip)
echo "eval \"\$(fnm env --use-on-cd)\"" >> ~/.zshrc
source ~/.zshrc

fnm install 20
fnm use 20
npm i -g pnpm
pnpm setup;
source ~/.zshrc;

git config --global core.editor 'code --wait'
git config --global user.name "Hyunwoo Lee"
git config --global user.email "epikem1@gmail.com"

# get gpg signing key for user.signingKey (need to generate one before run)
SIGNING_KEY=$(gpg --list-secret-keys --keyid-format LONG | grep sec | awk '{print $2}' | awk -F'/' '{print $2}')

# NOTE: manually install 'GPG indicator' extension in VSCode to unlock keys which passphrase is not empty

git config --global user.gpgSign true
git config --global user.signingKey "${SIGNING_KEY}"
git config --global init.defaultBranch "main"
git config --global commit.gpgSign true
# git config --global commit.program gpg2

# vscode extensions
code --install-extension ms-vscode-remote.remote-ssh

# install rustup: https://www.rust-lang.org/tools/install
# (interactive script)
# > curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
# (automatic script)
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
source "$HOME/.cargo/env"

# etc
brew install discord
brew install league-of-legends
# required after install: (open /opt/homebrew/Caskroom/league-of-legends/1.0/Install\ League\ of\ Legends\ na.app)

# 10688  cd install-sources
# 10689  ls
# 10690  git clone --depth 1 https://github.com/AstroNvim/AstroNvim ~/.config/nvim
# 10691  ls
# 10692  brew install nvim
# 10693  nvim
# 10694  ls
# 10695  cd ..
# 10696  ls
# 10697  cd repos/streami/gopax
# 10698  nvim .
# 10699  brew search nerd
# 10700  brew tap homebrew/cask-fonts
# 10701  brew install font-hack-nerd-font
# 10702  pnpm i -g tree-sitter-cli
# 10703  brew install jesseduffield/lazygit/lazygit
# 10704  brew install ripgrep
# 10705  brew install bottom
# 10706  brew install -f gdu
# 10707  brew link --overwrite gdu  # if you have coreutils installed as well
# 10708  nvim
